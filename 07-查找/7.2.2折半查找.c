一、折半查找
1.折半查找，又称“二分查找”，仅适用于有序的顺序表(顺序表具有随机访问的特性，链表没有)

2.代码实现：
typedef struct   //查找表的数据结构(顺序表)
{
	ElemType* elem; //动态数组
	int TableLen;   //表的长度
}SSTable;
int Binary_Search(SSTable L, ElemType key)
{
	int low = 0, high = L.TableLen - 1, mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (L.elem[mid] == key)
			return mid;
		else if (L.elem[mid] > key)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}

3.查找效率分析

4.折半查找判定树的构造：
若当前low和high之间有奇数个元素，则mid分隔后，左右两部分元素个数相等
若当前low和high之间有偶数个元素，则mid分隔后，左半部分比右半部分少一个元素

//折半查找的判定树中，若mid=(low+high)/2向下取整，则对于任何一个结点必有：
//右子树结点数-左子树结点数=0或1

折半查找的判定树一定是平衡二叉树
折半查找的判定树中，只有最下面一层是不满的
所以，元素个数为n时，树高h=log2(n+1)向上取整(注：该树高不包含失败结点)

判定树结点关键字：左<中<右,满足二叉排序树的定义
	失败结点：n+1个(等于成功结点的空链域数量)

5.折半查找的查找效率：
查找失败和成功的ASL都<=h
树高h = log2(n + 1)向上取整
折半查找的时间复杂度=O(log2n)

//折半查找的速度不一定比顺序查找跟快
例：当所要查找的元素在第一个时