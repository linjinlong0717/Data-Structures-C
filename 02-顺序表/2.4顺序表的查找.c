一、按位查找
//GetElem(L,i):按位查找操作。获取表L中第i个位置的元素的值。
1.(1).静态分配
//主要代码
#define MaxSize 10
typedef struct
{
	ElemType data[MaxSize];
	int length;
}SqList;
ElemType GetElem(SqList L, int i) //这里也可以判断i的值是否合法
{
	return L.data[i - 1];
}
(2)动态分配
//主要代码
#define InitSize 10
typedef struct
{
	ElemType* data;  //malloc函数返回的地址要转换为与data类型相同的指针
	int MaxSize;
	int length;
}SeqList;
ElemType GetElem(SeqList L, int i)
{
	return L.data[i - 1];
}
2.时间复杂度；O(1)

二、按值查找
//LocateElem(L,e):按值查找操作。在表L中查找具有给定关键字值的元素
1.
//主要代码
typedef struct
{
	int* data;
	int MaxSize;
	int length;
}SeqList;
int LocateElem(SeqList L, int e)
{
	for (int i = 0; i < L.length; i++)
	{
		if (L.data[i] == e) //注意两个结构体的比较不能直接用"=="，需要；依次对比各个分量
		{
			return i + 1;
		}
	}
	return 0;
}
2.时间复杂度：O(n)
