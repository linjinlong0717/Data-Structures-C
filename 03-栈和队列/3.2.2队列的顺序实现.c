一、
1.初始化操作
#define MaxSize 10
typedef struct
{
	ElemType data[MaxSize];
	int front, rear;//这里rear指向队尾元素的下一个位置
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
 
//判断非循环队列是否为空
bool QueueEmpty(SqQueue Q)
{
	if (Q.rear == Q.front)  return true;
	else  return false;
}

2.入队操作
bool EnQueue(SqQueue * Q, ElemType x)
{
	if (队列已满) return false;
	Q->data[Q->rear] = x;
	Q->rear = (Q->rear + 1)%MaxSize; //这里取余是为了假的溢出(循环队列)
	return true;
}

3.出队操作(只能让队头元素出队)
bool DeQueue(SqQueue * Q, ElemType * x)
{
	if (Q->rear == Q->front) return false;
	*x = Q->data[Q->front];
	Q->front = (Q->front + 1) % MaxSize;
	return true;
}

//判断循环队列是否已满/已空
法1：队满条件：队尾指针的再下一个位置是队头，即(Q->rear + 1) % MaxSize == Q->front
代价：牺牲一个存储单元(否则已满队列可能会被判断为空)
队空条件：Q->rear = q->front

法2：利用size记录队列的元素个数，插入成功size++，删除成功size--
队满条件：size == MaxSize
队空条件：size == 0

法3：利用tag(初始化为0)来表示最近进行的是删除 / 插入
每次删除成功，令tag = 0;
每次插入成功，令tag = 1;
队满条件：front == rear && tag == 1
队空条件：front == rear && tag == 0

//注意审题：rear指向的位置