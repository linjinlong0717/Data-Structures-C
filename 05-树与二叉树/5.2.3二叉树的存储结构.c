一、二叉树的顺序存储
#define MaxSize 100
struct TreeNode
{
	struct ElemType value;
	bool isEmpty; //初始化时所有结点标记为true
};
TreeNode t[MaxSize]; //定义一个长度为MaxSize的数组t，按照从上至下、从左至右的顺序依次存储完全二叉树中的各个结点

//i的左孩子为2i,右孩子为2i+1
若完全二叉树中共有n个结点，则
判断i是否有左孩子？-- 2i<=n?
判断i是否是叶子/分支结点？--i>(n/2)向下取整？

若不是完全二叉树，则在顺序存储中，一定要把二叉树的结点编号与完全二叉树对应起来
缺点；高度为h且只有h个结点的单支树(所有结点只右孩子)，也至少需要2的h次方-1个存储单元
所以二叉树的顺序存储结构，只适合存储完全二叉树

二、二叉树的链式存储
struct Elemtype
{
	int value;
};
typedef struct BiTNode
{
	struct ElemType data;
	struct BiTNode* lchild, * rchild;
}BiTNode,*BiTree;
//n个结点的二叉链表共有n+1个空链域(可以用于构造线索二叉树)

//定义一棵空树
BiTree root = NULL;

//插入根结点
root = (BiTree)malloc(sizeof(BiTNode));
root->data.value = 1;
root->lchild = NULL;
root->rchild = NULL;

//插入新节点
BiTNode* p = (BiTNode*)malloc(sizeof(BiTNode));
p->data.value = 2;
p->lchild = NULL;
p->rchild = NULL;
root->lchild = p;//作为根结点的左孩子

若要找到指定结点p的父结点，则只能从根结点开始遍历寻找
可以利用三叉链表(新增一个父结点指针)
