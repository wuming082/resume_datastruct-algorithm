#include <stdio.h>
#include <stdlib.h>
int newMallco()
{
    
}
typedef struct Linknode{
    int val;
    struct Linknode *next;
}Linknode;
//查找链表节点元素函数
int findNum(Linknode* head ,int findNum)
{
    while(head->next != NULL;)
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
//链表元素初始化函数
Linknode* newLinknode(int val)
{
    Linknode* node;
    node = ((Linknode*)malloc(sizeof(Linknode)));
    node->val = val;
    node->next = NULL;
    return node;
}
int main(){
    Linknode* n0 = newLinknode(2);
    Linknode* n1 = newLinknode(1);
    Linknode* n2 = newLinknode(9);
    Linknode* n3 = newLinknode(29);
    Linknode* n4 = newLinknode(4);
    Linknode* n5 = newLinknode(1);   
    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    printf("%d",find(n0,3));
    
    return 0;
}