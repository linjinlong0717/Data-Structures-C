一、KMP算法的优化，本质上是对next数组的优化
(next->nextval)

二、代码实现
先求出next数组，再由next数组求nextval数组
nextval[1] = 0;
for (int j = 2; j <= T.length; j++)
{
	if (T.ch[next[j]] == T.ch[j])
		nextval[j] = nextval[next[j]];
	else
		nextval[j] = next[j];
}