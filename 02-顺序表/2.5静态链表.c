#include <stdbool.h>
#define MAX_SIZE 100  
// 静态链表节点结构
typedef struct StaticNode 
{
    int data;     
    int next;     // 下一个节点的数组索引，-1表示空
    bool used;    // 节点是否被使用
} StaticNode;

// 静态链表结构
typedef struct 
{
    StaticNode nodes[MAX_SIZE];  // 节点数组                                                                           
    int head;                    // 数据链表头索引
    int free;                    // 空闲链表头索引
    int size;                    // 当前数据节
} StaticLinkedList;

// 初始化静态链表
void initList(StaticLinkedList* list) 
{
    list->head = -1;
    list->free = 0;
    list->size = 0;
    // 初始化所有节点，连接成空闲链表
    for (int i = 0; i < MAX_SIZE - 1; i++) 
    {
        list->nodes[i].data = 0;
        list->nodes[i].next = i + 1;
        list->nodes[i].used = false;
    }
    list->nodes[MAX_SIZE - 1].next = -1;
}
