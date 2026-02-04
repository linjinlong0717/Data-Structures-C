一、顺序栈
定义：顺序栈就是采用顺序存储结构实现的栈，也就是用数组来实现栈。

二、基本操作
1.初始化操作：
#define MaxSize 10
typedef struct
{
	ElemType data[MaxSize];
	int top;
}SqStack;
void InitStack(SqStack* S)
{
	S->top = -1;  //这里也可以初始化为0
}
int main ()
{
	SqStack S;
	InitStack(&S);
	//后续操作...
}

2.//判断栈是否为空
bool StackEmpty(SqStack S)
{
	if (S.top == -1) return true;
	else return false;
}

3.进栈操作
bool Push(SqStack * S, ElemType x)
{
	if (S->top == MaxSize - 1) return false;
	S->data[++S->top] = x;
	return true;
}

4.出栈操作
bool Pop(SqStack * S, ElemType * x)
{
	if (S->top == -1) return false;
	*x = S->data[S->top--];
	return true;
}

5.读栈顶元素
bool GetTop(SqStack S, ElemType * x)
{
	if (S.top == -1) return false;
	*x = S.data[S.top];
	return true;
}

三、共享栈
#define MaxSize 10
typedef struct
{
	ElemType data[MaxSize];
	int top0;
	int top1;
}ShStack;
//初始化栈
void InitStack(ShStack* S)
{
	S->top0 = -1;
	S->top1 = MaxSize;
}