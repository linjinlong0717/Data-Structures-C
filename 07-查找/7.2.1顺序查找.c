一、顺序查找
1.顺序查找，又叫“线性查找”，通常用于线性表
2.算法思想：从头到尾挨个找(反过来也可以)
3.代码实现：
typedef struct
{
	ElemType * elem;  //动态数组
	int TableLen;     //表的长度
}SSTable;
int Search_Seq(SSTable ST, ElemType key)
{
	int i;
	for (i = 0; i < ST.TableLen && ST.elem[i] != key; i++);
	return i == ST.TableLen ? -1 : i;
	//查找成功，则返回元素下标；查找失败，则返回-1
}

另一种代码实现(哨兵)：//优点：无需判断是否越界，效率更高
typedef struct
{
	ElemType* elem;
	int TableLen;
}SSTable;
int Search_Seq(SSTable ST, ElemType key)
{
	ST.elem[0] = key;  //"哨兵"
	int i;
	for (i = ST.TableLen; ST.elem[i] != key; i--);  //从后往前找
	return i; //查找成功，则返回元素下标；查找失败，则返回0
}

4.查找效率分析：(对哨兵的这种分析)
ASL=Pi*Ci从1到n的求和
ASL成功=(1+2+3+...+n)/n=(n+1)/2
ASL失败=n+1

5.顺序查找的优化(对有序表)
ASL失败=(1+2+3+...+n+n)/(n+1)=n/2+n/(n+1)
对于n个成功结点，有n+1种失败结点

用查找判定树分析ASL
一个成功结点的查找长度=自身所在层数
一个失败结点的查找长度=其父结点所在层数
//默认各种失败和成功情况都等概率发生

顺序查找的优化(被查概率不相等)
把被查概率大的放在靠前位置，可以缩短查找成功的平均查找长度
但查找失败的情况，又只能从头到尾了