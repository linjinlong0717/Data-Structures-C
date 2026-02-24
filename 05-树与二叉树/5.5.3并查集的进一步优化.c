一、并查集的终极优化
1.Find操作的优化(压缩路径)：
先找到根结点，再将查找路径上所有结点都挂在跟结点下

2.代码演示：
int Find(int S[], int x)
{
	int root = x;
	while (S[root] >= 0) root = S[root];
	while (x != root)
	{
		int t = S[x];
		S[x] = root;
		x = t;
	}
}
//每次Find操作，先找根，再“压缩路径”，可使树的高度不超过O(a(n)),a(n)是一个增长很缓慢的函数，
对于常见的n值，通常a(n)<=4，可以近似认为是 O(1)

3.时间复杂度分析：
(1)优化前:Find操作=最坏树高=O(n)
          将n个独立元素通过多次Union合并为一个集合 -- O(n的平方)
	//因为在Union之前都要Find找到根节点

(2)Union优化后：Find操作 = 最坏树高 = O(log2n)
              将n个独立元素通过多次Union合并为一个集合 -- O(nlog2n)

(3)Find优化后：Find操作 = 最坏树高 = O(a(n))
将n个独立元素通过多次Union合并为一个集合 -- O(na(n))