一、邻接表法(顺序+链式存储)  //类似于树的孩子表示法
//边/弧
typedef struct ArcNode
{
	int adjvex;    //边/弧指向结点数组下标
	struct ArcNode* next; //指向下一条弧的指针
	//InfoType info; //边权值
}ArcNode;
//顶点
typedef struct VNode
{
	VertexType data;  //顶点信息
	ArcNode* first;   //第一条边/弧
}VNode,AdjList[MaxVertexNum];
//用邻接表存储的图
typedef struct
{
	AdjList vertices;
	int vexnum, arcnum;
}ALGragh;

二、1.无向图：
边结点的数量为2|E|，整体的空间复杂度为O(|V|+2|E|)
2.有向图：
边结点的数量为|E|，整体的空间复杂度为O(|V|+|E|)
//适合用于存储稀疏图(稀疏图是指边数相对较少的图)

三、
//对于一个顶点来说，边没有顺序，所以图的邻接表示方式并不唯一
但是在邻接矩阵表示中，只要确定了顶点编号，图的邻接矩阵表示方式就是唯一的

//邻接表计算有向图的度、入度不方便
