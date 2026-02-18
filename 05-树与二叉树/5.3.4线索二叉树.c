一、线索二叉树的作用:
1.对于普通的二叉树，要找到指定结点p的前驱和后继结点，
要重新进行一次中序遍历，指针q记录当前访问的结点，
指针pre记录上一个被访问的结点
(1)当q==p时，pre为前驱
(2)当pre==p时，q为后继
//缺点：很不方便，必须从根开始

2.n个结点的二叉树，有n+1个空链域，可以用来记录前驱、后继的信息
前驱线索(由左孩子指针充当)
后继线索(由右孩子指针充当)

3.线索二叉树结点
typedef struct ThreadNode
{
	ElemType data;
	struct ThreadNode* lchild, * rchild;
	int ltag, rtag;  //左、右线索的标志
}ThreadNode,*ThreadTree;

//tag==0,表示指针指向孩子
 tag == 1, 表示指针是线索

//注意：某个结点的前驱和后继是由遍历顺序决定的 
例如：中序前驱、中序后继