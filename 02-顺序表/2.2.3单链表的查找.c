//本节都是基于带头结点的情况
一、按位查找
//主要代码演示：
LNode* GetElem(LinkList L, int i)
{
	if (i < 0) return NULL;
	LNode* p = L;
	int j = 0;
	while (p != NULL && j < i)
	{
		p = p->next;
		j++;
	}
	return p;
}
平均时间复杂度为：O(n)

//封装(基本操作)的好处：避免重复代码，简洁、易维护

二、按值查找
LNode* LocateElem(LinkList L, ElemType e)
{
	LNode* p = L->next;
	while (p!=NULL && p->data!=e)
	{
		p = p->next;
	}
	return p;
}
平均时间复杂度为：O(n)

//求表的长度
int Length(LinkList L)
{
	int len = 0;
	LNode* p = L;
	while (p->next!=NULL)
	{
		p = p->next;
		len++;
	}
	return len;
}
时间复杂度为：O(n)