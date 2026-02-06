一、例：(((( ))))
//最后出现的左括号 最先被匹配 (LIFO)--栈的特性
//每出现一个右括号，就"消耗"(出栈)一个左括号
//遇到左括号就入栈

二、算法实现
#define MaxSize 10
typedef struct
{
	char data[MaxSize];  //可以用链栈防止存满
	int top;
}SqStack;
//考试中可直接使用基本操作，建议简要说明借口

//初始化栈
void InitStack(SqStack *S)
//判断栈是否为空
bool StackEmpty (SqStack S)
//新元素入栈
bool Push (SqStack *S,char x)
//栈顶元素出栈，用x返回
bool Pop(SqStack *S,char *x)

bool bracketCheck(char str[], int length)
{
	SqStack S;
	InitStack(&S);
	for (int i = 0; i < length; i++)
	{
		if (str[i] == '(' || str[i] == '[' || str[i] == '{')
		{
			Push(&S, str[i]);
		}
		else
		{
			if (StackEmpty(S)) //防止右边过剩
			{
				return false;
			}
			char topElem;
			Pop(&S, &topElem);
			if (str[i] == ')' && topElem != '(')  return false;
			if (str[i] == ']' && topElem != '[')  return false;
			if (str[i] == '}' && topElem != '{')  return false;
		}
	}
	return StackEmpty(S);  //防止左边过剩
}