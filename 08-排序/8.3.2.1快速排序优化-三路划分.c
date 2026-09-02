//三路划分
void threewayPartition(vector<int>& v, int low, int high, int& l, int& r)
{
	l = low;
	r = high;
	int pivot = v[low];
	int i = low + 1;
	while (i <= r)
	{
		if (v[i] < pivot)	swap(v[i++], v[l++]);
		else
		{
			if (v[i] > pivot) swap(v[i], v[r--]);
			else	i++;
		}
	}
}
void threewaySort(vector<int>& v, int low, int high)
{
	if (low < high)
	{
		int l, r;
		threewayPartition(v, low, high, l, r);
		threewaySort(v, low, l - 1);
		threewaySort(v, r + 1, high);
	}
}
