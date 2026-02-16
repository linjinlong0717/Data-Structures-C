一、先/中/后序遍历：基于树的递归特性确定的次序规则
//先序遍历：根左右
  中序遍历：左根右
  后序遍历：左右根

1.先序遍历--第一次路过时访问结点
typedef struct BiTNode
{
	ElemType data;
	struct BiTNode* lchild, * rchild;
}BiTNode,*BiTree;
void PreOrder(BiTree T)
{

	if (T != NULL)
	{
		visit(T);  //访问根结点
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}

2.中序遍历--第二次路过时访问结点
InOrder(T->lchild);
visit(T);  //访问根结点
InOrder(T->rchild);

3.后序遍历--第三次路过时访问结点
PostOrder(T->lchild);
PostOrder(T->rchild);
visit(T);  //访问根结点

//空间复杂度为:O(n)

二、例：求树的深度(应用)
int treeDepth(BiTree T)
{
	if (T == NULL) return 0;
	else
	{
		int l = treeDepth(T->lchild);
		int r = treeDepth(T->rchild);
		//树的深度=Max(左子树深度，右子树深度)+1
		return l > r ? l + 1 : r + 1;
	}
}