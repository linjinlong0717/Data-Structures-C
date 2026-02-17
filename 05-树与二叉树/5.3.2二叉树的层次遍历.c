一、二叉树的层序遍历
1.算法思想：
(1)初始化一个辅助队列
(2)根结点入队
(3)若队列非空，则队头结点出队，访问该结点，并将其左、右孩子插入队尾(如果有的话)
(4)重复(3)的操作直到队列为空

2.代码实现：
//二叉树的结点(链式存储)
typedef struct BiTNode
{
	char data;
	struct BiTNode* lchild, * rchild;
}BiTNode,*BiTree;
//链式队列结点
typedef struct LinkNode
{
	BiTNode* data;  //存指针而不是结点(这样所需的内存空间更少)
	struct LinkNode* next;
}LinkNode;
typedef struct
{
	LinkNode* front, * rear;
}LinkQueue;
//层序遍历
void LevelOrder(BiTree T)
{
	LinkQueue Q;
	InitQueue(&Q);
	BiTree p;
	EnQueue(&Q, T);
	while (!IsEmpty(Q))
	{
		DeQueue(&Q, &p); //&p 就是二级指针
		visit(p);
		if (p->lchild != NULL) EnQueue(&Q, p->lchild);
		if (p->rchild != NULL) EnQueue(&Q, p->rchild);
	}
}