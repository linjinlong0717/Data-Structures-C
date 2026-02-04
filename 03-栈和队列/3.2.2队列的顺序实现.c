一、初始化操作
#define MaxSize 10
typedef struct
{
	ElemType data[MaxSize];
	int front, rear;
}SqQueue;
void InitQueue(SqQueue* Q)
{
	Q->front = Q->rear = 0;
}
int main()
{
	SqQueue Q;  //声明一个队列(顺序存储)
	InitQueue(&Q);
	//...后续操作...
}

//判断队列是否为空
bool QueueEmpty(SqQueue Q)
{
	if (Q.rear == Q.front)  return true;
	else  return false;
}