//二叉树线索化（Threaded Binary Tree）:
把二叉树中那些闲着的空指针（nullptr）利用起来，
让它们指向遍历序列中的前驱或后继节点。

一、中序线索化(C++)
ThreadNode* pre = nullptr;  //全局变量pre，指向当前访问的前驱
struct ThreadNode
{
	int data;
	struct ThreadNode* lchild, * rchild;
	bool ltag;  //false表示left指向左孩子，true表示left指向前驱线索
	bool rtag;  //false表示right指向右孩子，true表示right指向后驱线索

	ThreadNode(int val) : data(val), lchild(nullptr), rchild(nullptr),
		ltag(0), rtag(0) {}
};
void visit(ThreadNode* q)
{
	if (q->lchild == nullptr)
	{
		q->lchild = pre;
		q->ltag = 1;
	}
	if (pre != nullptr&& pre->rchild == nullptr)
	{
		pre->rchild = q;
		pre->rtag = 1;
	}
	pre = q;
}
typedef struct ThreadNode* ThreadTree;
void InThread(ThreadTree T)
{
	if (T != nullptr )
	{
		InThread(T->lchild);
		visit(T);
		InThread(T->rchild);
	}
}
void CreateInThread(ThreadTree T)
{
	pre = nullptr;
	if (T != nullptr)
	{
		InThread(T);
		if (pre->rchild == nullptr)
		{
			pre->rtag = 1;//处理最后一个结点
		}
	}
}
//一边遍历，一边线索化
//一般是中序遍历的线索化