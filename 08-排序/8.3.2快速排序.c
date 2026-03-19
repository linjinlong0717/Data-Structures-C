一、快速排序
1.算法思想：在待排序表L[1...n]中任取一个元素pivot作为枢轴(或基准，通常取首元素)，通过一趟排序将待排序表划分
为独立的两部分L[1...k - 1]和L[k + 1...n]，使得L[1...k - 1]中所有元素小于pivot，L[k + 1...n]中的所有元素大于等于
pivot，则pivot放在了其最终位置L(k)上，这个过程称为一次“划分”。然后分别递归地对两个子表重复上述过程，直至
每部分内只有一个元素或空为止，即所有元素放在了其最终位置上

2.算法实现：
int Partition(int A[], int low, int high)
{
	int pivot = A[low];
	while (low < high)    //用low、high搜索枢轴的最终位置
	{
		while (low < high && A[high] >= pivot) high--;
		A[low] = A[high];
		while (low < high && A[low] <= pivot) low++;
		A[high] = A[low];
	}
	A[low] = pivot;
	return low;  //返回存放枢轴的最终位置
}
void QuickSort(int A[], int low, int high)  
{
	if (low < high)      //递归跳出的条件
	{
		int pivotpos = Partition(A, low, high); //划分
		QuickSort(A, low, pivotpos - 1);       //划分左子表
		QuickSort(A, pivotpos + 1, high);      //划分右子表
	}
}

3.算法效率分析：
每一层的QuickSort只需处理剩余的待排序元素，时间复杂度不超过O(n)

把n个元素组织成二叉树，二叉树的层数就是递归调用的层数
n个结点的二叉树，最小高度= log2(n+1)向上取整；最大高度=n

时间复杂度=O(n*递归层数)  
最好时间复杂度=O(nlog2n)
最坏时间复杂度=O(n^2)   //若序列原本就有序或逆序，则时间复杂度最高(可优化，尽量选择可以把数据中分的枢轴元素)
平均时间复杂度=O(nlog2n)

空间复杂度 = O(递归层数)
最好空间复杂度=O(log2n)
最坏空间复杂度=O(n)

//若每一次选中的“枢纽”将待排序序列划分为均匀的两个部分，则递归深度最小，算法效率最高

快速排序算法优化思路：尽量选择可以把数据中分的枢纽元素
eg:(1)旋头、中、尾三个位置的元素，取中间值作为枢轴元素
(2)随机选一个元素作为枢轴元素

//快速排序是所有内部排序算法中平均性能最优的排序算法
快速排序是不稳定的

一次划分可以确定一个元素的最终位置，而一趟排序至少可以确定一个元素的最终位置