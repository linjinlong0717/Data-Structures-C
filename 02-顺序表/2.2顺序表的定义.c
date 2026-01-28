一、顺序表定义：
用顺序存储的方式实现线性表

二、顺序表的实现
(1)静态分配
//主要代码演示：
#include<stdio.h>
#define MaxSize 10
typedef struct
{
	int data[MaxSize];
	int length;
}SqList; 
void InitList(SqList* L)
{
	for (int i = 0; i < MaxSize; i++)
	{
		L->data[i] = 0;
	}
	L->length = 0;
}
int main()
{
	SqList L;
	InitList(&L);
	L.data[L.length] = 10;  
	L.length++;  

	L.data[L.length] = 20; 
	L.length++; 

	L.data[L.length] = 30;  
	L.length++;  
	return 0;
}

(2)动态分配   (利用c语言中的 malloc、free函数，加上头文件stdlib.h) //malloc函数返回一个指针，需要强制转换为你定义的数据元素类型指针
//主要代码演示：
#include <stdlib.h>
#define InitSize 10
typedef struct
{
	int* data;
	int MaxSize;
	int length;
}SeqList;
void InitList(SeqList* L)
{
	//用malloc函数申请一片连续的存储空间
	L->data = (int*)malloc(InitSize * sizeof(int));
	L->length = 0;
	L->MaxSize = InitSize;
}
void IncreaseSize(SeqList* L, int len)
{
	int* p = L->data;
	L->data = (int*)malloc((L->MaxSize + len) * sizeof(int));
	for (int i = 0; i < L->length; i++)
	{
		L->data[i] = p[i];
	}
	L->MaxSize = L->MaxSize + len;
	free(p);
}
int main()
{
	SeqList L;
	InitList(&L);
	//...往顺序表里面随便插入几个元素...
	IncreaseSize(&L,5);
	return 0;
}