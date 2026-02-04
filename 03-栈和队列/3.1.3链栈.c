一、
1.链栈就是用链表实现的栈。 //相当于头插法建立单链表

二、链栈的定义
typedef struct Linknode
{
	ElemType data;
	struct Linknode* next;
}*LiStack;
