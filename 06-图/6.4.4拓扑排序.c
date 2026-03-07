//AOV网(Activity On Vertex Network,用顶点表示活动的网)：
用DAG图(有向无环图)表示一个工程。顶点表示活动，有向边<Vi,Vj>表示活动Vi必须先于活动Vj进行

一、拓扑排序--找到做事的先后顺序
1.定义1：在图论中，由一个有向无环图的顶点组成的序列，当且仅当满足下列条件时，称为该图的一个拓扑排序：
(1)每个顶点出现且只出现一次
(2)若顶点A在序列中排在顶点B的前面，则在图中不存在从顶点B到顶点A的路径

定义2：拓扑排序是对有向图的顶点的一种排序，它使得若存在一条从顶点A到顶点B的路径，
则在排序中顶点B出现在顶点A的后面。每个AOV网都有一个或多个拓扑排序序列

2.算法思路：
(1)从AOV网中选择一个没有前驱(入度为0)的顶点并输出
(2)从网中删除该顶点和所有以它为起点的有向边
(3)重复(1)和(2)直到当前的AOV网为空或当前网中不存在无前驱的顶点为止(有回路)

3.代码实现：
#define MaxVertexNum 100
typedef struct ArcNode  //边表结点
{
	int adjvex;
	struct ArcNode * nextarc;//指向依附于该顶点下一条弧
}ArcNode;
typedef struct VNode  //顶点表结点
{
	VertexType data;
	ArcNode * firstarc;//指向第一条依附于该顶点的弧
}VNode,AdjList[MaxVertexNum];
typedef struct
{
	AdjList vertices;  //邻接表
	int vexnum, arcnum; //顶点数和弧数
}Graph;
bool TopologicalSort(Graph G)
{
	InitStack(S); //初始化栈(也可以用队列)
	for (int i = 0; i < G.vexnum; i++)
	{
		if (indegree[i] == 0)  Push(&S, i);  //indegree[]数组记录当前结点的入度
		int count = 0;
	}
		while (!IsEmpty(S))
		{
			Pop(&S, i);
			print[count++] = i;  //print[]数组用于记录拓扑序列			
			for (int p = G.vertices[i].firstarc; p; p = p->nextarc)
			{
				v = p->adjvex;
				if (!(--indegree[v])) Push(&S, v);  //入度为0，则入栈

			}
		}
		if (count < G.vexnum) return false;
		else return true;
}

//因为每个顶点和边都需要处理一次
时间复杂度：O(|V|+|E|)
若采用邻接矩阵，则需O(|V|的平方)

二、逆拓扑排序
1.对于一个AOV网，若采用下列步骤进行排序，则称之为逆拓扑排序：
(1)从AOV网中选择一个没有后继(出度为 0)的顶点并输出
(2)从网中删除该顶点和所有以它为终点的有向边
(3)重复(1)和(2)直到当前的AOV网为空

2.逆拓扑排序的实现：
法1：用逆邻接表(每个顶点后面连接的是指向该顶点的弧)
//代码实现和拓扑排序类似

法2：用到DFS算法
void DFSTraverse(Graph G)
{
	for (int v = 0; v < G.vexnum; v++)
		visited[v] = FALSE;
	for (int v = 0; v < G.vexnum; v++)
		if (!visited[v]) DFS(G, v);
}
void DFS(Graph G, int v)
{
	visited[v] = TRUE;
	for(int w=FirstNeighbor(G,v);w>=0;w=NextNeighbor(G,v,w))
		if (!visited[w])
		{
			DFS(G, w);
		}
	print(v);//输出顶点
}
//在顶点退栈前输出
思考：若存在回路，则如何判断回路？
可以引入三色标记法