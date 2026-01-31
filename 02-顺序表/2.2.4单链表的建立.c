//以带头结点为例
一、尾插法建立单链表
//主要代码演示：
LinkList List_TailInsert(LinkList* L)
{
	int x;
	*L = (LinkList)malloc(sizeof(LNode));
	LNode* s, * r = *L;  //r为表尾指针
	scanf("%d", &x);
	while (x != 9999)
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		scanf("%d", &x);
	}
	r->next = NULL;
	return *L;
}
时间复杂度为：O(n)

二、头插法建立单链表
//主要代码演示：
LinkList List_HeadInsert(LinkList* L)
{
	LNode* s;
	int x;
	*L = (LinkList)malloc(sizeof(LNode));
	(*L)->next = NULL;   //注意运算的优先级
	scanf("%d", &x);
	while (x != 9999)
	{
		s= (LinkList)malloc(sizeof(LNode));  //这里相当于对头指针进行尾插操作
		s->data = x;
		s->next = (*L)->next;
		(*L)->next = s;
		scanf("%d", &x);
	}
	return *L;
}
//头插法的重要应用：链表的逆置