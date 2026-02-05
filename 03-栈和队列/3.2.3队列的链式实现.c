一、链队列--链式存储实现的队列
1.初始化(带头结点)
typedef struct LinkNode
{
	ElemType data;
	struct LinkNode* next;
}LinkNode;
typedef struct
{
	LinkNode* front, * rear;
}LinkQueue;

void InitQueue(LinkQueue* Q)
{
	Q->front = Q->rear = (LinkNode *)malloc(sizeof(LinkNode));
	Q->front->next = NULL;
}

int main()
{
	LinkQueue Q;
	InitQueue(&Q);
	//...后续操作...
}

//判断队列是否为空
bool IsEmpty(LinkQueue Q)
{
	if (Q.front == Q.rear) return true;
	else return false;
}

初始化(不带头结点)
void InitQueue(LinkQueue* Q)
{
	Q->front = NULL;
	Q->rear = NULL;
}

//判断队列是否为空
bool IsEmpty(LinkQueue Q)
{
	if (Q.front == NULL) return true;
	else return false;
}

2.入队操作(带头结点)  //队尾插入
void EnQueue(LinkQueue * Q, ElemType x)
{
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;
	Q->rear->next = s;
	Q->rear = s;
}

入队(不带头结点)
void EnQueue(LinkQueue* Q, ElemType x)
{
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;
	if (Q->front == NULL)
	{
		Q->front = s;
		Q->rear = s;
	}
	else
	{
		Q->rear->next = s;
		Q->rear = s;
	}
}

3.出队操作(带头结点)  //队头出队
bool DeQueue(LinkQueue * Q, ElemType * x)
{
	if (Q->front == Q->rear)   //空队
		return false;
	LinkNode* p = Q->front->next;
	*x = p->data;
	Q->front->next = p->next;
	if (Q->rear == p)
		Q->rear = Q->front;
	free(p);
	return true;
}

出队(不带头结点)
bool DeQueue(LinkQueue* Q, ElemType* x)
{
	if (Q->front == NULL)  return false;
	LinkNode* p = Q->front;
	*x = p->data;
	Q->front = p->next;
	if (Q->rear == p)
	{
		Q->front = NULL;
		Q->rear = NULL;
	}
	free(p);
	return true;
}
//注意是否带头结点，删除时是否最后一个元素，增加时是否第一个元素，可以用int型变量记录链队列长度