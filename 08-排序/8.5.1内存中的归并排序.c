一、归并排序
1.归并：把两个或多个已经有序的序列合并成一个
//利用i,j,k三个变量，分别指向要合并的两个数组和一个存放合并后的元素的数组

//分为外部排序和内部排序

2.内部排序的代码实现：
int* B = (int*)malloc(n * sizeof(int));  //辅助数组B
//A[low...mid]和A[mid+1...high]各自有序，将两个部分归并
void Merge(int A[], int low, int mid, int high)
{
	int i, j, k;
	for (k = low; k <= high; k++)
		B[k] = A[k];
	for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++)
	{
		if (B[i] <= B[j]) A[k] = B[i++];
		else  A[k] = B[j++];
	}
	while (i <= mid)   A[k++] = B[i++];
	while (j <= high)  A[k++] = B[j++];
}
void MergeSort(int A[], int low, int high)  //运用到递归
{
	if (low < high)
	{
		int mid = (low + high) / 2;   //从中间划分
		MergeSort(A, low, mid);       //对左半部分归并排序
		MergeSort(A, mid+1, high);    //对右半部分归并排序
		Merge(A, low, mid, high);     //归并
	}
}

3.算法效率分析：
//注意：2路归并的“归并树”--形态上就是一棵倒立的二叉树

二叉树的第h层最多有 2^(h-1) 个结点 
若树高为h，则应满足 n<=2^(h-1)
即 h-1=log2n 向上取整

结论：n个元素进行2路归并排序，归并趟数=log2n向上取整
每趟归并时间复杂度为O(n)，则算法时间复杂度O(nlog2n)

空间复杂度=O(n),来自于辅助数组B(递归深度小于log2n,所以，空间复杂度主要来自辅助数组B)

4.归并排序是稳定的