一、循环单链表
typedef struct LNode
{
	ElemType data;
	struct LNode* next;
}LNode,*LinkList;
//初始化一个循环单链表
bool InitList(LinkList* L)
{
	*L = (LNode*)malloc(sizeof(LNode));
	if (*L == NULL) return false;
	(*L)->next = *L;
	return true;
}
//判断循环单链表是否为空
bool Empty(LinkList L)
{
	if (L->next == L) return true;
	else return false;
}
//技巧：很多时候对链表的操作都是在头部或尾部，
可以让L指向表尾元素，这样时间复杂度就为O(1)

二、循环双链表
typedef struct DNode
{
	ElemType data;
	struct DNode* prior, * next;
}DNode,*DLinkList;
//初始化双链表
bool InitDLinkList(DLinkList* L)
{
	*L = (DNode*)malloc(sizeof(DNode));
	if (*L == NULL) return false;
	(*L)->prior = *L;
	(*L)->next = *L;
	return true;
}
int main()
{
	DLinkList L;
	InitDLinkList(&L);
    //后续代码...
}

//循环双链表的插入
bool InsertNextDNode(DNode* p, DNode* s)
{
	if (p == NULL || s == NULL) return false;
	s->next = p->next;
	p->next->prior = s;
	s->prior = p;
	p->next = s;
	return true;
}

//循环双链表的删除操作(删除p的后继结点q)
p->next = q->next;
q->next->prior = p;
free(q);