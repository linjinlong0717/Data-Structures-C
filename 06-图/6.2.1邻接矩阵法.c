一、图的存储--邻接矩阵法
1.#define MaxVertexNum 100
typedef struct
{
	char Vex[MaxVertexNum]; //顶点中可以存更复杂的信息
	int Edge[MaxVertexNum][MaxVertexNum];  //可以用bool型或枚举型变量表示边
	int vexnum, arcnum;//图的当前顶点数和边数/弧数
}MGraph;

2.结点数为为n的图G = (V, E)的邻接矩阵A是n * n的。将G的顶点编号为v1, v2, ..., vn, 则
A[i][j] = 1，  则(vi, vj)或(vj, vi)是E(G)中的边
= 0，  则(vi, vj)或(vj, vi)不是E(G)中的边

3.对于无向图：(不考虑自环)
第i个结点的度 = 第i行(或第i列)的非零元素个数

对于有向图：
第i个结点的出度 = 第i行的非零元素个数
第i个结点的入度 = 第i列的非零元素个数
第i个结点的度 = 第i行、第i列的非零元素个数之和

//邻接矩阵法求顶点的度/出度/入度的时间复杂度为O(|V|)

4.邻接矩阵法存储带权图(网)
#define MaxVertexNum 100
#define INFINITY 最大的int值  //宏定义常量“无穷”
typedef char VertexType;//顶点的数据类型
typedef int EdgeType; //带权图中边上权值的数据类型
typedef struct
{
	VertexType Vex[MaxVertexNum];//顶点
	EdgeType Edge[MaxVertexNum][MaxVertexNum];//边的权
	int vexnum, arcnum;
}MGraph;

//邻接矩阵法：
空间复杂度：O(|V|的平方)--只和顶点数相关，和实际的边数无关
适用于存储稠密图

无向图的邻接矩阵是对称矩阵，可以压缩存储(只存储上三角区/下三角区)

5.邻接矩阵的性质；
设图G的邻接矩阵为A(矩阵元素为0/1)，则A^n的元素A^n[i][j] 等于由
顶点i到顶点j的长度为n的路径的数目