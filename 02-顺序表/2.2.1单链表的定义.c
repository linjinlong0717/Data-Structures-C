一、1.单链表与顺序表
(1)顺序表(顺序存储)
优点：可以随机存取，存储密度高
缺点 : 要求大片连续空间，改变容量不方便
(2)单链表(链式存储)
优点：不要求大片连续空间，改变容量方便
缺点：不可随机存取，要耗费一定空间存放指针

二、用代码定义一个单链表
//可以利用typedef进行数据类型的重命名(简洁)
typedef <数据类型> <别名>
typedef struct LNode LNode;
typedef struct LNode
{
  //...
}*LinkList;//LinkList是指向struct LNode类型的指针
//LNode *L;与LinkList L;是等价的。前者强调这是一个结点，后者强调这是一个链表

1.不带头结点的单链表(从第一个结点开始)
//主要代码：
typedef struct LNode
{
	ElemType data;
	struct LNode* next;
}LNode,*LinkList;
bool InitList(LinkList * L)
{
	*L = NULL;
	return true;
}
//判断单链表是否为空
bool Empty(LinkList L)
{
	return (L == NULL);
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
2.带头结点的单链表(头结点相当于第零个结点)
typedef struct LNode
{
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;
bool InitList(LinkList* L)
{
	*L = (LNode*)malloc(sizeof(LNode));
	if (*L == NULL)
		return false;
	(*L)->next = NULL;//易错
	return true;
}
int main()
{
	LinkList L;
	InitList(&L);
	//h后续代码
}