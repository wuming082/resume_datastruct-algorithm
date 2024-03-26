#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
//创建二叉树结构体
typedef struct Treenode{
    int val;
    int high;
    struct Treenode* left;
    struct Treenode* right;
}Treenode;

//初始化二叉树结构体函数
Treenode* newTreenode(int val)
{
    Treenode* node = malloc(sizeof(Treenode));
    node->val = val;
    node->high = 0;
    node->left = NULL;
    node->right = NULL;
    return node;
}
//创建链表节点结构体
typedef struct Linknode{
    struct Linknode* next;
    struct Linknode* fount;
    Treenode* node;
}Linknode;
//队列结构体
typedef struct listnode{
    Linknode* fount;//队头
    Linknode* rear;//对尾
    int size;
}listnode;
//初始化队列函数
listnode* newlistnode()
{
    listnode* node = malloc(sizeof(listnode));
    node->fount = NULL;
    node->rear = NULL;
    node-> size = 0;
    return node;
}
//入队函数
void putlistnode(listnode* list,Treenode* node)
{
    Linknode* transfer = malloc(sizeof(Linknode));
    //先将叶节点与链表元素节点绑定
    transfer->node = node;
    if(list->fount == NULL || list->rear == NULL)
    {
       list->fount = transfer;
       list->rear = transfer;
    }
    list->fount->fount = transfer;
    transfer->next = list->fount;
    list->fount = transfer;
    list->size++;
}
//出队函数
Linknode* returnTreeout(listnode* list)//推出相应叶节点
{
    //从尾队列退出相应叶节点
    if(list->fount == NULL || list->rear == NULL )
    {
        printf("目标队列无内含元素，参数错误");
        return NULL;
    }
    Linknode* node= malloc(sizeof(Linknode));
    node =malloc(sizeof(Treenode));
    node = list->rear;
    list->rear = list->rear->fount;
    return node;

}
//创建广度搜索二叉树结构体
typedef struct Traversal{
    int *arr;//承接遍历结果指针数组
    listnode *Tnode;//用于暂存此层数所存放的当前节点
    int Sizenode;//当前节点数量
}Traversal;
//创建二叉树广度搜索遍历函数
int* widefindTreenode(Treenode* root)
{
    int capacity = 50 ,extendNum = 2;//定义存储空间,定义扩大倍速  
    Traversal* node = malloc(sizeof(Traversal));
    //先分配给数组一定空间
    node->arr =malloc(sizeof(int) * capacity);
    //分配给Tnode相应空间
    node->Tnode = malloc(sizeof(listnode));
    node->Tnode->size = 0;
    //初始化节点数量
    node->Sizenode = 0;
    //先将根节点放入队列当中
    putlistnode(node->Tnode,root);    
    //开始遍历
    int index =0;
    int count;
    while(node->Tnode->rear != NULL)//此针对完美二叉树
    {
        for(count = 0 ; count < node->Tnode->size ; count++){
            //搜索此节点的下层节点
            printf("%d",node->Tnode->rear->node->left->val);  
            putlistnode(node->Tnode,node->Tnode->rear->node->left);
            index++;
            printf("%d",node->Tnode->rear->node->right->val);
            putlistnode(node->Tnode,node->Tnode->rear->node->right);
            index++;
            returnTreeout(node->Tnode); //出队
        }
    }
}
int main()
{
    Treenode* n0 = newTreenode(2);
    Treenode* n1 = newTreenode(5);
    Treenode* n2 = newTreenode(1);
    Treenode* n3 = newTreenode(10);
    Treenode* n4 = newTreenode(58);
    Treenode* n5 = newTreenode(10);
    Treenode* n6 = newTreenode(6);
    n0->left = n1;
    n0->right = n2;
    n1->left = n3;
    n1->right = n4;
    n2->left = n4;
    n2->right = n5;
    widefindTreenode(n0);
    return 0;
}
*/
//////////////////////基于队列（数组）二叉树广度遍历算法///////////////////////////
//树节点结构体
typedef struct Treenode{
    int val;
    struct Treenode* left;
    struct Treenode* right;
}Treenode;
//初始化树节点
Treenode* newTreenode(int val)
{
    Treenode* node = malloc(sizeof(Treenode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}
//二叉树遍历函数
int* TreenodetraversalFunction(Treenode* transfer)
{
    int *arr;
    int fount = 0 , rear = 0;
    Treenode** Tnode;
    Treenode* node;
    Tnode = malloc(sizeof(Treenode) * 100);
    node = malloc(sizeof(Treenode));
    arr = malloc(sizeof(int) * 100);
    int index = 0;
    //将根节点放入队列
    Tnode[rear++] = transfer;
    while(fount < rear)
    {
        node = Tnode[fount++];
        arr[index++] = node->val;//不能将此语句放入if语句当中，因为如果此方式，则不能遍历到根节点
        if(node->left != NULL)
        {
            Tnode[rear++] = node->left;
            //arr[index++] = node->left->val;
        }
        if(node->right != NULL)
        {
            Tnode[rear++] = node->right;
            //arr[index++] = node->right->val;
        }
    }
    return arr;
}
//前序遍历//////////////////////////////////////////////////////////////////////////////////////////
void preOrder(Treenode* node)
{
    if(node == NULL)
        return;
    printf("%d",node->val);
    preOrder(node->left);
    preOrder(node->right);
}
int main()
{
    Treenode* n0 = newTreenode(1);
    Treenode* n1 = newTreenode(2);
    Treenode* n2 = newTreenode(3);
    Treenode* n3 = newTreenode(4);
    Treenode* n4 = newTreenode(5);
    Treenode* n5 = newTreenode(6);
    Treenode* n6 = newTreenode(7);
    n0->left = n1;
    n0->right = n2;
    n1->left = n3;
    n1->right = n4;
    n2->left = n5;
    n2->right = n6;
    printf("前序遍历二叉树=");
    preOrder(n0);
    printf("\n中序遍历二叉树=");
    preOrder(n0);
    printf("\n后序遍历二叉树=");
    preOrder(n0);
    //int *reivce = TreenodetraversalFunction(n0);
    //for(int i = 0 ; i < 7 ; i++)
    //{
    //    printf("%d\n",reivce[i]);
    //}
    return 0;
}
////////////////////////////////////////////////////////////////////////////////
