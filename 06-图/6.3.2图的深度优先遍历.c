一、图的深度优先遍历
1.bool visited[MAX_VERTEX_NUM];
void DFS(Graph G, int v)
{
	visit(v);
	visited[v] = TRUE;
	for (int w = Firstneighbor(G, v); w >= 0; w = Nextneighbor(G, v, w))
	{
		if (!visited[w])
		{
			DFS(G, w);
		}
	}
}
//若是非连通图，则无法遍历完所有结点

2.DFS算法(Final版)
在1.的前面加上
void DFSTraverse(Graph G)
{
	for (int v = 0; v < G.vexnum; v++)
	{
		visited[v] = FALSE;
	}
	for (int v = 0; v < G.vexnum; v++)
	{
		if (!visited[v])
		{
			DFS(G, v);
		}
	}
}

3.空间复杂度：来着函数调用栈
最坏情况(所有顶点连成直线)，递归深度为O(|V|)
最好情况(一个顶点连接其他所有顶点)，递归深度为O(1)

4.时间复杂度分析:访问各结点所需时间+探索各条边所需时间
用邻接矩阵存储的图(遍历序列唯一)：
访问|V|个顶点需要O(|V|)的时间
查找每个顶点的邻接点都需要O(|V|)的时间，而总共有|V|个顶点
时间复杂度=O(|V|的平方)

用邻接表存储的图(遍历序列不唯一)：
访问|V|个顶点需要O(|V|)的时间
查找各个顶点的邻接点共需要O(|E|)的时间
时间复杂度=O(|V|+|E|)

二、1.深度优先生成树
对连通图的深度优先遍历过程中，每个顶点第一次被访问时所经过的边，
和所有顶点一起构成的图，就是一棵树，叫深度优先生成树。

2.深度优先生成森林
对非连通图的深度优先遍历，可得到深度优先生成森林

三、图的遍历与图的连通性
1.对无向图进行BFS/DFS遍历
调用BFS/DFS函数的次数=连通分量数

对于连通图，只需调用1次BFS/DFS

2.对于有向图进行BFS/DFS遍历
调用BFS/DFS函数的次数要具体问题具体分析

若起点顶点到其他各顶点都有路径，则只需要调用1次BFS/DFS函数

对于强连通图，从任一结点出发都只需调用1次BFS/DFS