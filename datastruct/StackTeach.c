#include<stdio.h>
#include<stdlib.h>
/*
链表
typedef struct Linknode{
    int val;
    struct Linknode *next;
}Linknode;
*/
//查找链表节点元素函数
/*

int findNum(Linknode* head ,int findNum)
{
    while(head->next != NULL)
    {
        int i++;
        if(findNum == head->val)
            return i;
    }    
}


//链表查找索引相应元素函数
int find(Linknode* head,int findNum)
{
    for(int i = 0 ; i < findNum ; i++)
    {
        if(head->next == NULL)
            return 0;
        head = head->next;
    }
    return head->val;
}
//链表删除节点函数
int delete (Linknode* det0)//删除接收节点的后节点
{
    if(det0->next == NULL)
        return 0;
    Linknode* det1 = det0->next;
    Linknode* det2 = det1->next;
    det0->next = det2;
    //释放内存
    free(det1);
}
//链表添加函数
void insert(Linknode* A,Linknode* B)
{
//创建中转节点
    Linknode* transfer = A->next;
    A->next = B;
    B->next = transfer;
}
*/
//链表元素初始化函数
//链表
//int returnNum(stack* transfer)
//{
//   return transfer->top->val;
//}
typedef struct Linknode{
    int val;
    struct Linknode* next;
}Linknode;
//栈
typedef struct stack{
    Linknode* top;
    int size;
}stack;
Linknode* newLinknode(int val)
{
    Linknode* node;
    node = ((Linknode*)malloc(sizeof(Linknode)));
    node->val = val;
    node->next = NULL;
    return node;
}

//创建栈 函数
stack* newStack(){
   stack* node = (malloc(sizeof(stack)));
   node->size = 0;
   node->top = NULL;
   return node;
}
//查看元素大小
int returnSize (stack* transfer){
    return transfer->size;
}

//是否为空元素
int Epsize (stack* transfer){
    if(transfer->size == 0)
        return 1;
    else return 0;
}

//入栈函数
void pressStack(stack* transfer,int val){
    Linknode* node = malloc(sizeof(Linknode));
    node->next = transfer->top;//错误更改前，该语句在
    node->val = val;
    transfer->top = node;//此句上方/////////////////////////////////////////////                  
    transfer->size++;
}
//出栈函数
void outStack(stack* transfer){
    Linknode* node = malloc(sizeof(Linknode));
    node = transfer->top;
    transfer->top = transfer->top->next;
    free(node);
    transfer->size--;
}
int main ()
{
    stack* newTest = newStack();
    pressStack(newTest,2);
    pressStack(newTest,1);
    pressStack(newTest,5);
    pressStack(newTest,7);
    pressStack(newTest,4);
    pressStack(newTest,9);
    pressStack(newTest,10);
    pressStack(newTest,23);
    printf("目前的栈内元素为；%d",returnSize(newTest));
    pressStack(newTest,14);
    outStack(newTest);
    outStack(newTest);
    printf("栈头元素为；%d",newTest->top->val);
    printf("目前的栈内元素为；%d",returnSize(newTest));
    return 0;
}