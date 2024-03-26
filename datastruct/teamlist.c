#include<stdio.h>
#include<stdlib.h>
//链表节点结构体
typedef struct Linknode{
    int val;
    struct Linknode* next;
}Linknode;
//队列结构体
typedef struct Teamlist{
    int size;
    Linknode* fount;//队头元素
    Linknode* rear;//队尾元素
}Teamlist;
//初始化链表
Linknode* newLinknode(int val)
{
    Linknode* node = ((Linknode*)malloc(sizeof(Linknode)));
    node->val = val;
    node->next = NULL;
    return node;
}
//初始化队列
Teamlist* newTeamlist()
{
    Teamlist* node = ((Teamlist*)malloc(sizeof(Teamlist)));
    node->size = 0;
    node->fount = NULL;
    node->rear = NULL;
    return node;
}
//查看队列大小
int checkTeam (Teamlist* node)
{
    if(node->size == 0)
        return -1;
    else
        return node->size;
}
//入队函数
void inputTeamlist(Teamlist* transfer,int val)
{
    Linknode* node = (Linknode*)malloc(sizeof(Linknode));
    if(transfer->fount == NULL){
        node->val =val;
        transfer->fount = node;
        transfer->rear = node;
        transfer->size++;
    }
    else{
    //如果队列不为空元素，则将节点放到队尾
        node->val =val;
        transfer->rear->next = node;
        transfer->rear = node;
        transfer->size++;
    }
}
//查看队头元素
int Teamlistfirst(Teamlist* transfer)
{
    if(transfer->fount == NULL)
        return -1;
    else
        return transfer->fount->val;
}
int main()
{
    //创建链表
    Teamlist* new = newTeamlist();
    inputTeamlist(new,2);
    inputTeamlist(new,1);
    inputTeamlist(new,10);
    printf("元素数值为：%d",Teamlistfirst(new));
    return 0;
}
