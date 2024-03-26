#include<stdio.h>
#include<stdlib.h>
//树节点结构体
typedef struct Treenode{
    int val;
    int high;
    struct Treenode* left;
    struct Treenode* right;
}Treenode;
//初始化树节点函数
Treenode* newTreenode(int val)
{
    Treenode* node = (Treenode*)malloc(sizeof(Treenode));
    node->val = val;
    node->high = 0;
    node->left = NULL;
    node->right = NULL;
    return node;
}


int main()
{
    return 0;
}