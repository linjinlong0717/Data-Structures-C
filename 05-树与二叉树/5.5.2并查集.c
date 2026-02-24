一、逻辑结构 --“集合”
将各个元素划分为若干个互不相交的子集
//类似：森林是m(m>=0)z棵互不相交的树的集合
所以，同一子集的各个元素，组织成一棵树

二、如何“查”到一个元素属于哪个集合？
从指定元素出发，一直向上，找到根结点

如何判断两个元素是否属于同一个集合 ?
分别查到两个元素的根，判断根结点是否相同即可

如何把两个集合“并”为一个集合？
让一棵树成为另一棵树的子树即可

三、并查集的存储结构--双亲表示法(用int类型数组表示父结点的位置，根结点数组的值为负数)

四、代码实现
1.初始化
#define SIZE 13
int UFSets[SIZE]; //集合元素数组
//初始化并查集
voId Initial(int S[])
{
	for (int i = 0; i < SIZE; i++)
	{
		S[i] = -1;
	}
}
2.查操作
int Find(int S[], int x)
{
	while (S[x] >= 0)
	{
		x = S[x];
	}
	return x;
}
最坏时间复杂度：O(n)
3.并操作
void Union(int S[], int Root1, int Root2)
{
	if (Root1 == Root2) 
		return;
	S[Root2] = Root1;//将根Root2连接到另一个根Root1下面
}
时间复杂度：O(1)

五、Union优化思路
1.用根结点的绝对值表示树的结点总数
2.Union操作，让结点数少的树合并到结点树多的树

优化后Union代码：
void Union(int S[], int Root1, int Root2)
{
	if (Root1 == Root2) return;
	if (S[Root2] > S[Root1])
	{
		S[Root1] += S[Root2];
		S[Root2] = Root1;
	}
	else
	{
		S[Root2] += S[Root1];
		S[Root1] = Root2;
	}
}
//用该方法构造的树高不超过log2n向下取整+1
所以Union操作优化后，Find操作最坏时间复杂度：O(log2n)