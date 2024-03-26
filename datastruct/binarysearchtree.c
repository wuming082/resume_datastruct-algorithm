//二叉搜索树的最主要的条件
//左叉树的值 < 根节点值 < 右叉书的值
//在添加时,需要用pre中间变量，来去进行赋值，可以保存到上层的叶节点值
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//树节点结构人
typedef struct Treenode{
    int val;
    struct Treenode* left;
    struct Treenode* right;
}Treenode;
//初始化二叉树结构体
Treenode* newTreenode(int Num)
{
    Treenode* node = malloc(sizeof(Treenode));
    node->val = Num;
    node->left = NULL;
    node->right = NULL;
    return node;
}
//二叉搜索树函数
Treenode* findTreenode(Treenode * transfer,int Num)
{
    Treenode * node = malloc(sizeof(Treenode));
    node = transfer;
    while(node != NULL)
    {
        if(Num > node->val)//向右节点
            node = node->right;
        else if(Num < node->val)//向左节点
            node = node->left;
        else
            break;
    }
    return node;
}
//添加二叉树节点函数
Treenode* insertTreenode(Treenode* transfer, int Num)
{
    Treenode* pre;
    Treenode* cur = transfer;
    while(cur != NULL)
    {   
        /*/////////err代码
        if(node->right == Num)//已被占用，退出函数
                return NULL;
            else if(node->right == NULL)
            {
                
            }
        *////////////////
        pre = cur;
        if(Num < cur->val)//向左节点
            cur = cur->left;
        else if(Num > cur->val)//向右节点
             cur= cur->right;
        else
        {
            printf("此节点已被占用,ERR!");
            return NULL;
        }   
    }
    Treenode* node = newTreenode(Num);
    if(Num > pre->val)
        pre->right = node;
    else
        pre->left = node;

}
///////////////////////////////////////////////////////////////////////////
//二叉树删除节点函数
Treenode* deleteTreenode(Treenode* transfer,int val)
{
    //分为两种情况 一，被删除节点的度为0/1  二，被删除节点的度为0
    
}
/*
Treenode* cur = transfer , pre = NULL;
    while(cur != NULL)
    {
        //找到相应节点返回
        if(cur->val ==val)
        break;
        pre = cur;
        if(cur->val > val)//向左节点
            cur = cur-left;
        if(cur->val < val)//向右节点
            cur = cur-right;
    }
    if(cur == NULL)
        return;
    Treenode* ndoe = cur;
    //查看此节点的下层节点个数
    if(cur->left == NULL || cur->right == NULL){
        //此节点的下层节点 = 1/0
        if(cur->left != NULL){
            cur = cur->left;
            while(cur != Null){
                    pre = cur;
                    cur = cur->right;
            }
            //找到替代节点并赋值
            node->val = pre->val;
        }
        else{
            //左侧节点为空值
            cur = cur->right;
             while(cur != Null){
                    pre = cur;
                    cur = cur->left;
            }
            //找到替代节点并赋值
            node->val = pre->val;
        }
        pre
    }
    else if(cur->left != NULL && cur->right != NULL){
        //下层节点为2

    }
    else{
        //下层没有节点，直接进行代替
        
    }


    
    

}
*/
/*
Treenode* deleteTreenode(Treenode* transfer, int val)
{
    //初始化中转节点结构体
    Treenode* node = malloc(sizeof(Treenode));
    node = newTreenode(0);
    //判断节点位置
    if(val == transfer->val){
        printf("err");
    }
    else if(val > transfer->val)//向右节点搜索
    {
        ndoe = transfer->right;
    }
}
*/



