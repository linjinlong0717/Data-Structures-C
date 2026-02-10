一、串的顺序存储
#define MAXLEN 255
typedef struct
{
	char ch[MAXLEN];  //静态数组实现(定长顺序存储)
	int length;
}SString;

typedef struct
{
	char* ch;          //动态数组实现(堆分配存储)
	int length;
}HString;
HString S;
S.ch = (char*)malloc(MAXLEN * sizeof(char)); //用完需要手动free
S.length = 0;

二、串的链式存储
typedef struct StringNode  //存储密度低，每个字符1B，每个指针4B
{
	char ch;             
	struct StringNode* next;
}StringNode,*String;
typedef struct StringNode  //存储密度提高
{
	char ch[4];
	struct StringNode* next;
}StringNode, * String;

三、基本操作的实现
1.求子串
bool SubString(SString * Sub, SString S, int pos, int len)
{
	if (pos + len - 1 > S.length) return false; //这里的S第0个位置不放字符
	for (int i = pos; i < pos + len; i++)
	{
		Sub->ch[i - pos + 1] = S.ch[i];
	}
	Sub->length = len;
	return true;
}
2.比较操作(若S > T, 则返回值 > 0; 若S = T, 则返回值 = 0;若S<T,则返回值<0)
int StrCompare(SString S, SString T)
{
	for (int i = 1; i <= S.length && i <= T.length; i++)
	{
		if (S.ch[i] != T.ch[i]) return S.ch[i] - T.ch[i];
	}
	return S.length - T.length;
}
3.index(S,T):定位操作。若主串S中存在与串T值相同的子串,则返回它在主串S中第一次出现的位置；否则函数值为0
int Index(SString S, SString T)
{
	int i = 1, n = StrLength(S), m = StrLength(T);
	SString sub;
	while (i <= n - m + 1)
	{
		SubString(&sub, S, i, m);
		if (StrCompare(sub, T) != 0)  i++;
		else return i;
	}
	return 0;
}