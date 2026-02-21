一、中序线索二叉树找中序后继
//找到以p为根的子树中，第一个被中序遍历的结点
ThreadNode* Firstnode(ThreadNode* p)
{
	while (p->ltag == 0) p = p->lchild;
	return p;
}
//在中序线索二叉树中找到结点p的后继结点
ThreadNode* Nextnode(ThreadNode* p)
{
	if (p->rtag == 0) return Firstnode(p->rchild);
	else return p->rchild;
}
//对中序线索二叉树进行中序遍历(利用线索实现的非递归算法)
void Inorder(ThreadNode* T)
{
	for (ThreadNode* p = Firstnode(T); p != NULL; p = Nextnode(p))
	{
		visit(p);
	}
}

二、中序线索二叉树找中序前驱
//找到以p为根的子树中，最后一个被中序遍历的结点
ThreadNode* Lastnode(ThreadNode* p)
{
	while (p->rtag == 0) p = p->rchild;
	return p;
}
//在中序线索二叉树中找到结点p的前驱结点
ThreadNode* Prenode(ThreadNode* p)
{
	if (p->ltag == 0) return Lastnode(p->lchild);
	else return p->lchild;
}
//对中序线索二叉树进行逆向中序遍历
void RevInorder(ThreadNode* T)
{
	for (ThreadNode* p = Lastnode(T); p != NULL; p = Prenode(p))
	{
		visit(p);
	}
}

三、先序线索二叉树找先序前驱
(1)若能找到p的父结点，且p是左孩子，则p的父结点为其前驱
(2)若能找到p的父结点，且p是右孩子，其左兄弟为空，则p的父结点为其前驱
(3)若能找到p的父结点，且p是右孩子，其左兄弟非空，则p的前驱为左兄弟子树中最后一个被先序遍历的结点
(4)若p是根结点，则p没有先序前驱

四、后序线索二叉树找后序后继
(1)若能找到p的父结点，且p是右孩子，则p的父结点为其后继
(2)若能找到p的父结点，且p是左孩子，其右兄弟为空，则p的父结点为其后继
(3)若能找到p的父结点，且p是左孩子，其右兄弟非空，则p的后继为右兄弟子树中第一个被后序遍历的结点
(4)若p是根结点，则p没有后序后继

//注意：对于中序二叉树找前驱和后继都可以找
而先序线索二叉树找前驱和后序线索二叉树找后继要用三叉链表或从根开始遍历寻找