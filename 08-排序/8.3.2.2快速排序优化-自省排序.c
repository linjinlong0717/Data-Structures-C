#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath> //调用log2(n)
using namespace std;
void insertSort(vector<int>& v, int low, int high)
{
	for (int i = low + 1; i <= high; i++)
	{
		if (v[i-1] > v[i])
		{
			int j;
			int temp = v[i];
			for (j = i - 1; j >= low && v[j] > temp; j--)
			{
				v[j + 1] = v[j];
			}
			v[j + 1] = temp;
		}
	}
}
int partition(vector<int>& v, int low, int high)
{
	int pivot = v[low];
	while (low < high)
	{
		while (low < high && v[high] >= pivot) high--;
		v[low] = v[high];
		while (low < high && v[low] <= pivot) low++;
		v[high] = v[low];
	}
	v[low] = pivot;
	return low;
}
void introSortHelper(vector<int>& v, int low, int high, int depthLimit)
{
	if (low >= high) return;
	const int INSERT_THRESHOLD = 16;
	if (high - low + 1 <= INSERT_THRESHOLD)
	{
		insertSort(v, low, high);
		return;
	}
	if (depthLimit <= 0)
	{
		make_heap(v.begin() + low, v.begin() + high + 1);
		sort_heap(v.begin() + low, v.begin() + high + 1);
		return;
	}
	int pivotpos = partition(v, low, high);
	introSortHelper(v, low, pivotpos - 1, depthLimit - 1);
	introSortHelper(v, pivotpos + 1, high, depthLimit - 1);
}
int main()
{
	vector<int>arr = { 9,3,7,1,8,2,6,4,5,0 };
	int n = static_cast<int>(arr.size());
	int depthLimit = static_cast<int>(2 * log2(n));
	introSortHelper(arr, 0, n - 1, depthLimit);
	return 0;
}

//自省排序的思路：
1.判断是否小于等于 16：如果是 → 插入排序，直接返回（结束）

2.判断递归深度是否超标：如果是 → 堆排序，直接返回（结束）

3.如果以上都不满足：执行快速排序分区

4.分区后，对左右子数组分别递归（深度 + 1）, 回到第 1 步

//自省排序 还可以与 三路划分 结合