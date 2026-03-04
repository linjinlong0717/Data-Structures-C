一、图的广度优先遍历(BFS)
1.//与树的广度优先遍历对比，
树在搜索相邻结点时，不可能搜到已经访问过的结点
图在搜索相邻顶点时，有可能搜到已访问过的顶点

2.要点：标记被访问过的顶点
        要一个辅助队列

3.代码实现:
bool visited[MAX_VERTEX_NUM];  //访问标记数组，初始都为false
void BFS(Graph G, int v)
{
    Queue Q;
    InitQueue(&Q);
    visit(v);
    visited[v] = true;
    EnQueue(&Q, v);
    while (!isEmpty(Q))
    {
        DeQueue(&Q, &v);
        for (int w=Firstneighbor(G,v);w>=0;w=Nextneighbor(G,v,w)
        {
            if (!visited[w])
            {
                visit(w);
                visited[w] = true;
                EnQueue(&Q, w);
            }
        }
    }
}

4.同一个图的邻接矩阵表示方式唯一，因此广度优先遍历序列唯一
  同一个图的邻接表示方式不唯一，因此广度优先遍历序列不唯一

5.算法存在的问题：
如果是非连通图，则无法遍历完所有结点
结论：对于无向图，调用BFS函数的次数=连通分量数

改进版代码：
void BFSTraverse(Gragh G)
{
    for (int i = 0; i < G.vexnum; i++)
    {
        visited[i] = false;
    }
    InitQueue(&Q);
    for (int i = 0; i < G.vexnum; i++)
    {
        if (!visited[i])
        {
            BFS(G, i);
        }
    }
}

6.复杂度分析：
空间复杂度：最坏情况，辅助队列大小为O(|V|)

邻接矩阵存储的图：
访问|V|个顶点需要O(|V|)的时间
查找每个顶点的邻接点都需要O(|V|)的时间，而总共有|V|个顶点
总的时间复杂度=O(|V|的平方)

邻接表存储的图：
访问|V|个顶点需要O(|V|)的时间
查找每个顶点的邻接点共需要O(|E|)的时间
总的时间复杂度=O(|V|+|E|)

二、1.广度优先生成树：
对连通图的广度优先遍历过程中，每个顶点第一次被访问时所经过的边，
和所有顶点一起构成的图，就是一棵树，叫广度优先生成树。

//广度优先生成树是由于广度优先遍历过程确定。
邻接表的广度优先生成树不唯一
邻接矩阵的广度优先生成树唯一

2.广度优先生成森林：
对非连通图的广度优先遍历，可得到广度优先生成森林