#include<stdio.h>
#include<stdlib.h>
//创建动态数组结构体
typedef struct ArrayTeam{
    int fount;
    int arrSize;//累计元素大小
    int *arr;
    int size;
    int capacity;
}ArrayTeam;
//初始化动态数组结构体函数
ArrayTeam* newArrayTeam()
{
    ArrayTeam* node = malloc(sizeof(ArrayTeam));
    node->capacity = 12;
    node->fount = 0;
    node->arrSize = 0 ;
    node->size = 0;
    node->arr=malloc(sizeof(int) * node->capacity);
    return node;
}
//访问队列元素大小
int checkTeamszie(ArrayTeam* node)
{
    return node->size;
}
//访问队列容量大小
int checkTeamcapacity(ArrayTeam* node)
{
    return node->capacity;
}
//入队函数
int put(ArrayTeam* transfer,int val)
{
    if(transfer->size == transfer->capacity)
    {
        printf("err,out");
        return 0;
    }
    int rear = (transfer->fount + transfer->arrSize) % transfer->capacity;
    transfer->arr[rear] = val;
    transfer->arrSize++;
}
//出队函数
int out(ArrayTeam* transfer)
{
    if(transfer->arrSize == 0)
    {
        printf("err,zero");
        return 0;
    }
    int Num = transfer->arr[transfer->fount];
    transfer->fount = (transfer->fount + 1) % transfer->capacity;//直接改变头部索引
    transfer->arrSize--;
    return Num;
}
int main()
{
    ArrayTeam* node = newArrayTeam();
    put(node,2);
    put(node,1);
    put(node,10);
    put(node,13);
    put(node,7);
    put(node,8);
    put(node,9);
    put(node,10);
    put(node,122);
    //put(node,22);
    //put(node,111);
    //put(node,85);
    //put(node,1112);
    put(node,12);
    put(node,3);
    put(node,2);
    out(node);
    put(node,101);
    put(node,555);
    out(node);
    for(int i = 0 ; i < 12 ;i++)
    {
        printf("%d\n",node->arr[i]);
    }
    printf("目前元素大小为 = %d\n头部元素为 = %d",node->arrSize,node->arr[node->fount]);
    return 0;
}