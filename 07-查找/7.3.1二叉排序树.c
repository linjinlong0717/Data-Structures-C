一、二叉排序树(二叉查找树)(BST,Binary Search Tree) --可用于元素的有序组织、搜索
1.定义：左子树上所有结点的关键字均小于根结点的关键字
        右子树上所有结点的关键字均大于根结点的关键字
        左子树和右子树又各是一棵二叉排序树
    //左子树结点值<根结点值<右子树结点值
    这样进行中序遍历，可以得到一个递增的有序序列

2.二叉排序树的查找的代码实现1：
typedef struct BSTNode
{
    int key;
    struct BSTNode* lchild, * rchild;
}BSTNode,*BSTree;
BSTNode* BST_Search(BSTree T, int key)
{
    while (T != NULL && key != T->key) //若树空或等于根结点值，则结束循环
    {
        if (key < T->key) T = T->lchild;//小于，则在左子树上查找
        else T = T->rchild;             //大于，则在右子树上查找
    }
    return T;
}
最坏空间复杂度：O(1)

代码实现2(递归版)：
BSTNode* BSTSearch(BSTree T, int key)
{
    if (T == NULL) return NULL;
    if (key == T->key) return T;
    else if (key < T->key) return BSTSearch(T->lchild, key);
    else  return BSTSearch(T->rchild, key);
}
最坏空间复杂度：O(h)

3.二叉排序树的插入代码实现(递归实现)： //最坏空间复杂度O(h)
int BST_Insert(BSTree * T, int k)  //注意：若插入的是空二叉排序树，则需要修改原BSTreet指针的值，所以要用到二级指针
{
    if (*T == NULL)
    {
        *T = (BSTree)malloc(sizeof(BSTNode));
        (*T)->key = k;
        (*T)->lchild = (*T)->rchild = NULL;
        return 1; //返回1，插入成功
    }
    else if (k == (*T)->key)
        return 0; //树中存在相同关键字的结点，插入失败
    else if (k < (*T)->key)
        return BST_Insert(&(*T)->lchild, k);
    else 
        return BST_Insert(&(*T)->rchild, k);
}

4.二叉排序树的构造
void Creat_BST(BSTree * T, int str[], int n)
{
    *T = NULL;  //初始时*T为空树
    int i = 0;
    while (i < n)
    {
        BST_Insert(T,str[i]);
        i++;
    }
}
//不同的关键字序列可能得到相同二叉排序树，也可能得到不同的二叉排序树

5.二叉排序树的删除
(1)若被删除结点z是叶结点，则直接删除，不会破坏二叉排序树的性质
(2)若结点z只有一棵左子树或右子树，则让z的子树成为z父结点的子树，替代z的位置
(3)若结点z有左、右两棵子树，则令z的直接后继(或直接前驱)替代z，然后从二叉排序树中删去这个
直接后继(或直接前驱)，这样就转换成了第一或第二种情况
//此时z的后继：z的右子树中最左下结点(该结点一定没有左子树)
               z的左子树中最右下结点(该结点一定没有右子树)

6.查找效率分析：
查找长度--在查找运算中，需要对比关键字的次数称为查找长度

最好情况：n个结点的二叉树最小高度为log2(n+1)向上取整
平均查找长度=O(log2n)

最坏情况：每个结点只有一个分支，树高h=结点数n
平均查找长度=O(n)