一、KMP算法(是对朴素模式匹配算法的改进) //不需要回溯
1.主要代码：
int Index_KMP(SString S, SString T, int next[])
{
	int i = 1, j = 1;
	while (i < S.length && j <= T.length)
	{
		if (j == 0 || S.ch[i] == T.ch[j])
		{
			i++;
			j++;
		}
		else  j = next[j];
	}
	if (j > T.length) return i - T.length;
	else return 0;
}

2.最坏时间复杂度：O(m+n)
其中，求next数组时间复杂度O(m)
模式匹配过程最坏时间复杂度O(n)

3.求next数组     
next[j] = 重复片段长度（最长相等前后缀长度） + 1

4.KMP算法代码完整版(优化前)
#include <stdio.h>
#include <string.h>
#define MAXLEN 255                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
// 定长顺序存储结构（下标1开始存储字符）
typedef struct 
{
    char ch[MAXLEN + 1];    // ch[0]闲置，从ch[1]开始存
    int length;             // 串的当前长度
} SString;
// 构建next数组（经典版）- 适配下标1开始
void getNext(SString T, int next[]) 
{
    int i = 1, j = 0;
    next[1] = 0;            // next[1] = 0 表示第一个字符失配时，主串指针后移
    while (i < T.length) 
    {
        if (j == 0 || T.ch[i] == T.ch[j]) 
        {
            i++;
            j++;
            next[i] = j;    // 长度为i的前缀的最长相等前后缀长度为j
        }
        else 
        {
            j = next[j];    // 回溯到更短的前缀
        }
    }
}
int Index_KMP(SString S, SString T, int next[]) 
{
    int i = 1, j = 1;
    while (i <= S.length && j <= T.length) 
    {
        if (j == 0 || S.ch[i] == T.ch[j]) 
        {
            i++;
            j++;
        }
        else 
        {
            j = next[j];
        }
    }
    if (j > T.length) 
    {
        return i - T.length;    // 匹配成功，返回在主串中的起始下标
    }
    else 
    {
        return 0;               // 匹配失败
    }
}
// 初始化字符串（从普通C字符串转换为SString，下标1开始）
void initString(SString* s, char* str) 
{
    s->length = strlen(str);
    for (int i = 0; i < s->length; i++) 
    {
        s->ch[i + 1] = str[i];
    }
}
// ----- 测试代码 -----
int main()
{
    SString S, T;
    int next[MAXLEN + 1];
    // 测试用例
    initString(&S, "ababcabcabababd");
    initString(&T, "ababd"); 
    getNext(T, next);
    int pos = Index_KMP(S, T, next);
    if (pos) 
    {
        printf("匹配位置: %d\n", pos);
    }
    else 
    {
        printf("未找到匹配\n");
    }
    return 0;
}