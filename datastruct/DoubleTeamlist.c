#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
//双向链表结构体
typedef struct Doublelinknode{
    int val;
    struct Doublelinknode* fount;
    struct Doublelinknode* next;
}Doublelinknode;
//初始化链表结构体
Doublelinknode* newDoublelinknode(int val)
{
    Doublelinknode* node;
    node = (Doublelinknode*)malloc(sizeof(Doublelinknode));
    node->next = NULL;
    node->fount = NULL;
    node->val = val;
    return node;
}
//双队列结构体
typedef struct DoubleTeamlist{
    int size;
    Doublelinknode* fount;
    Doublelinknode* rear;
}DoubleTeamlist;
//初始化双队列结构体
DoubleTeamlist *newDoubleTeamlist()
{
    DoubleTeamlist* node;
    node = (DoubleTeamlist*)malloc(sizeof(DoubleTeamlist));
    node->rear = NULL;
    node->fount = NULL;
    node->size = 0;
    return node;
}
//查看队列元素个数函数
int checkDoubleTeamlistSize(DoubleTeamlist* node)
{
    return node->size;
}
//入队函数（头/尾）
void push (DoubleTeamlist* transfer,int val,bool option)
{
    Doublelinknode* node = newDoublelinknode(val);
    if(transfer->size == 0)
    {
        transfer->fount = node;
        transfer->rear = node;
        transfer->size++;
    }
    else if(option)//为真，头部入队
    {
        transfer->fount->fount = node;
        node->next = transfer->fount;
        transfer->fount = node;
        transfer->size++;
    }
    else//为假，尾部入队
    {
        transfer->rear->next = node;
        node->fount =transfer->rear;
        transfer->rear = node;
        transfer->size++;
    }
}
//出队函数（头尾)
int pop (DoubleTeamlist* transfer,bool option)
{
    //assert(transfer->fount == NULL || transfer->rear ==NULL);
    if(option)//为真，头部出队
    {
        Doublelinknode* node;
        int val = transfer->fount->val;
        node = transfer->fount->next;
        free(transfer->fount);
        transfer->fount = node;
        transfer->size--;
        return val;
    }
    else//为假，尾部出队
    {
        Doublelinknode* node;
        int val = transfer->rear->val;
        node = transfer->rear->fount;
        free(transfer->rear);
        transfer->rear = node;
        transfer->size--;
        return val;
    }
}
//查看队列元素
int checkDoubleTeamlistFount(DoubleTeamlist* node,bool option)
{
    //assert(node->rear == NULL || node->fount == NULL);
    if(option)//为真打印头元素；
        return node->fount->val;
    else
        return node->rear->val;
}
int main()
{
    DoubleTeamlist* newD = newDoubleTeamlist();
    //头部入队
    push(newD,3,true);
    push(newD,5,true);
    push(newD,5,true);
    push(newD,1,true);
    push(newD,4,true);
    push(newD,7,true);
    push(newD,13,true);
    pop(newD,false);
    pop(newD,true);
    //pop(newD,false);

    printf("目前队头元素位 = %d\n对尾元素 = %d\n队列大小为 = %d",checkDoubleTeamlistFount(newD,true),checkDoubleTeamlistFount(newD,false),checkDoubleTeamlistSize(newD));
    return 0;
}