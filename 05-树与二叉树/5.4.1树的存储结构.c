一、双亲表示法(顺序存储)
#define MAX_TREE_SIZE 100
typedef struct
{
	ElemType data;
	int parent;   //用int类型的变量记录父结点在数组中的位置
}PTNode;
typedef struct
{
	PTNode nodes[MAX_TREE_SIZE];
	int n;
}PTree;

优点：找父结点很方便
缺点：找孩子不方便，只能从头到尾遍历整个数组
适用于并查集

二、孩子表示法(顺序存储+链式存储)
struct CTNode
{
	int child;
	struct CTNode* next;
};
typedef struct
{
	ElemType data;
	struct CTNode* firstChild;
}CTBox;
typedef struct
{
	CTBox nodes[MAX_TREE_SIZE];
	int n, r;  //结点数和根的位置
}CTree;
优点：找孩子很方便
缺点：找父结点不方便，只能遍历每个链表
适用于“找孩子”多，“找父亲”少的场景，如服务流程树

三、孩子兄弟表示法(链式存储) //与二叉树类似
typedef struct CSNode
{
	ElemType data;
	struct CSNode* firstchild, * nextsibling;//第一个孩子和右兄弟指针
}CSNode,CSTree;
//若要表示森林，则森林中的每棵树的根结点视为平级的兄弟关系