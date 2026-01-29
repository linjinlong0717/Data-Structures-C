一、顺序表的插入
1.//主要代码示例
#include<stdio.h>
#include<stdbool.h>
#define MaxSize 10
typedef struct
{
	int data[MaxSize];
	int length;
}SqList;
void InitList(SqList * L)
{
	L->length = 0;
}
bool ListInsert(SqList* L, int i, int e)
{
	if (i<1 || i>L->length + 1)
		return false;
	if (L->length >= MaxSize)
		return false;
	for (int j = L->length; j >= i; j--)
	{
		L->data[j] = L->data[j - 1];
	}
	L->data[i - 1] = e;
	L->length++;
	return true;
}
int main()
{
	SqList L;
	InitList(&L);
	//...此处省略一些代码，插入几个元素
	ListInsert(&L, 3, 3);
	return 0;
2.时间复杂度分析：
平均情况：假设新元素插入到任何一个位置的概率相同(都是p=1/(n+1))，
所以平均循环次数 = n/2

二、顺序表的删除
1.//主要代码示例
bool ListDelete(SqList * L,int i,int * e)
{
	if (i<1 || i>L->length)
	{
		return false;
	}
	*e = L->data[i - 1];
	for (int j = i; j < L->length; j++)
	{
		L->data[j - 1] = L->data[j];  //注意数组下标与位序的对应关系
	}
	L->length--;
	return true;
}
int main()
{
	SqList L;
	InitList(&L);
	//...此处省略一些代码，插入几个元素"带回来"
	int e = -1;
	if (ListDelete(&L, 3, &e))
		printf("已删除第3个元素，删除元素值为=%d\n", e);
	else
		printf("位序i不合法，删除失败\n");
	return 0;
}
2.时间复杂度分析：
平均循环次数(n - 1) / 2;