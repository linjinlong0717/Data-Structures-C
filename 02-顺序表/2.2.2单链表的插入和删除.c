一、单链表的插入
1.按位序插入(带头结点)
//主要代码演示：
typedef struct LNode
{
	ElemType data;
	struct LNode* next;
}LNode,*LinkList;
bool ListInsert(LinkList* L, int i, ElemType e)
{
	if (i < 1) return false;
	LNode* p;     //指针p指向当前扫描到的结点
	int j = 0;    //当前p指向的是第几个结点
	p = *L;       //L指向头结点，头结点是第0个结点(不存数据)
	while (p != NULL && j < i - 1) //循环找到第i-1个结点
	{
		p = p->next;
		j++;
	}
	if (p == NULL) return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p -> next = s;
	return true;
}
平均时间复杂度：O(n)

2.按位序插入(不带头结点)  //要对插入第一个位置的情况单独处理
//主要代码演示：
bool ListInsert(LinkList * L, int i, ElemType e)
{
	if (i < 1) return false;
	if (i == 1)
	{
		LNode* s = (LNode*)malloc(sizeof(LNode));
		s->data = e;
		s->next = *L;
		*L = s;
		return true;
	}
	//后面的操作与带头结点的操作相同
}
//题目没有要求的话，用带头结点会更方便

3.指定结点的后插操作
//其实和1.中的差不多

4.指定结点的前插操作
//主要代码演示：
法1：bool InsertPriorNode(LNode * p, ElemType e)
{
	if (p == NULL) return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL) return false; //内存分配失败
	s->next = p->next;
	p->next = s;
	s->data = p->data;
	p->data = e;
	return true;
}
时间复杂度为：O(1)

法2：传入头指针，循环查找p的前驱q，再对q后插
时间复杂度为：O(n)

二、单链表的删除
1.按位序删除(带头结点)
//主要代码演示：
bool ListDelete(LinkList * L, int i, ElemType * e)
{
	LNode* p=*L;
    //...循环找到i-1个结点
	LNode* q = p->next;
	*e = q->data;
	p->next = q->next;
	free(q);
	return true;
}

2.指定结点的删除(指定结点p)
//主要代码演示：
bool DeleteNode(LNode * p)
{
	if (p == NULL) return false;
	LNode* q = p->next;
	p->data = q->data;
	p->next = q->next;
	free(q);
	return true;
}
//如果删除的是最后一个结点，则只能从表头依次往后找