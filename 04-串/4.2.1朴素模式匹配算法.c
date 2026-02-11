一、字符串模式匹配
在主串中找到与模式串相同的子串, 并返回其所在位置。
//有朴素模式匹配算法、KMP算法

二、朴素模式匹配算法(主串长度为n，模式串长度为m。将主串中所以长度为m的子串依次与模式串对比，直到找到一个完全匹配的子串，或所有的子串都不匹配为止)
//可以用定位操作Index(S,T)  (上一节内容)
也可以用数组下标实现：
int Index(SString S, SString T)
{
	int i = 1, j = 1;
	while (i <= S.length && j <= T.length)
	{
		if (S.ch[i] == T.ch[j])
		{
			i++;
			j++;
		}                                
		else
		{
			i = i - j + 2;
			j = 1;
		}
	}
	if (j > T.length) return i - T.length;
	else return 0;
}
//最坏时间复杂度=O(nm)
共n - m + 1个子串，每个子串都要对比m次，最坏时间复杂度 = O((n - m + 1) * m) = O(nm)
