//最短路径问题
1.单源最短路径
(1)BFS算法(无权图)
(2)Dijkstra算法(带权图、无权图)
2.各顶点间的最短路径
Floyd算法(带权图、无权图)

//无权图可以视为一种特殊的带权图，只是每条边的权值都为1

一、BFS算法实现最短路径问题
d[]数组表示从起点到当前结点的最短路径长度（即经过的边数）
path[]数组表示从起点到当前结点的最短路径中，当前结点的前一个结点（前驱结点）。

void BFS_MIN_Distance(Graph G, int u)
{
	for (int i = 0; i < G.vexnum; i++)
	{
		d[i] = 无穷;
		path[i] = -1;
	}
	d[u] = 0;
	visited[u] = TRUE;
	EnQueue(&Q, &u);
	while (!isEmpty(Q))
	{
		DeQueue(&Q, u);
		for (int w = Firstneighbor(G, u); w >= 0; w = Nextneighbor(G, u, w))
		{
			if (!visited[w])
			{
				d[w] = d[u] + 1;
				path[w] = u;
				visited[w] = TRUE;
				EnQueue(Q, w);
			}
		}
	}
}
//通过path数组可以得到最短路径序列
//BFS算法求单源最短路径只适用于无权图，或所有边的权值都相同的图
