一、双链表的初始化(带头结点)
//主要代码演示：
typedef struct DNode
{
	ElemType data;
	struct DNode* prior, * next;
}DNode,*DLinkList;
//初始化双链表                
bool InitDLinkList(DLinkList* L)
{
	*L = (DNode*)malloc(sizeof(DNode));
	if (*L == NULL)
		return false;
	(*L)->prior = NULL;
	(*L)->next = NULL;
	return true;
}
int main()
{
	//初始化双链表
	DLinkList L;
	InitDLinkList(&L);
	//后续代码
}

//判断双链表是否为空(带头结点)
bool Empty(DLinkList L)
{
	if (L->next == NULL)
		return true;
	else
		return false;
}

二、双链表的插入(在p结点之后插入s结点)
bool InsertNextDNode(DNode* p, DNode* s)
{
	if (p == NULL || s == NULL) return false;
	s->next = p->next;
	if (p->next != NULL) p->next->prior = s;
	p->next = s;
	s->prior = p;
	return true;
}

三、双链表的删除(删除p结点的后继结点)
bool DeleteNextDNode(DNode* p)
{
	if (p == NULL) return false;
	DNode* q = p->next;
	if (q == NULL) return false;
	p->next = q->next;
	if (q->next != NULL)
		q->next->prior = p;
	free(q);
	return true;
}
//那么删除这个双链表就可以：
void DestroyList(DLinkList* L)
{
	while ((*L)->next != NULL)
	{
		DeleteNextDNode(*L);
	}
	free(*L);
	*L = NULL;
}

四、双链表的遍历
1.后向遍历
while (p != NULL)
{
	//对结点p做相应处理
	p = p->next; 
}
2.前向遍历
while (p != NULL)  //若不处理头结点，则循环条件改成p->prior!=NULL
{
	//对结点p做相应处理
	p = p->prior;
}
时间复杂度为：O(n)