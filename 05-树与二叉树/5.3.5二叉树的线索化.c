一、中序线索化
ThreadNode* pre = NULL;  //全局变量pre，指向当前访问的前驱
typedef struct ThreadNode
{
	ElemType data;
	struct ThreadNode* lchild, * rchild;
	int ltag, rtag;

};
void visit(ThreadNode* q)
{
	if (q->lchild == NULL)
	{
		q->lchild = pre;
		q->ltag = 1;
	}
	if (pre != NULL && pre->rchild == NULL)
	{
		pre->rchild = q;
		pre->rtag = 1;
	}
	pre = q;
}
void InThread(ThreadTree T)
{
	if (T != NULL)
	{
		InThread(T->lchild);
		visit(T);
		InThread(T->rchild);
	}
}
void CreateInThread(ThreadTree T)
{
	pre = NULL;
	if (T != NULL)
	{
		InThread(T);
		if (pre->rchild == NULL)
		{
			pre->rtag = 1;//处理最后一个结点
		}
	}
}
//一边遍历，一边线索化

二、后序线索化
与中序线索化类似

三、前序线索化
void PreThread(ThreadTree T)
{
	visit(T);
	if (T->ltag == 0)     //注意：这里要判断是否为线索(否则会出现死循环)
	{
		PreThread(T->lchild);
	}
	PreThread(T->rchild);
}
