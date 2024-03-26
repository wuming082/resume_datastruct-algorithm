#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Treenode{
    int val;
    int hight;
    struct Treenode *left;
    struct Treenode *right;
}Treenode;
//初始化二叉树节点函数
Treenode* newTreenode (int val){
    Treenode* node = malloc(sizeof(Treenode));
    node->val = val;
    node->hight = 0;
    node->left = NULL;//左节点
    node->right = NULL;//右节点
    return node;
}
//获取高度函数
int hight(Treenode* node){
    //如果为空对象，返回-1
    if(node == NULL)
        return -1;
    return node->hight;
}
//更新节点函数
void updataTree (Treenode* node){
    if(node == NULL){
        printf("err");
        return;
    }
    int rN = hight(node->right);
    int rL = hight(node->left);
    //判断左右叶节点的最大高度，赋值= 最大高度 + 1
    if(rL > rN)
        node->hight = rL + 1;
    else
        node->hight = rN + 1;
}
//获取平衡因子函数
int reBanlceNum (Treenode* node){
    if(node == NULL)
        return 0;
    else
        return hight(node->left) - hight(node->right);
}
//右旋节点函数
Treenode* rightTrans(Treenode* node){
    if(node == NULL){//提高稳定性
        printf("err");
        return NULL;
    }
    Treenode* child,*grand_child;//创建旋转中心节点，旋转中心右叶节点
    child = node->left;
    /*
    //如果旋转中心右叶节点为NULL
    if(child->right == NULL)
        grand_child = NULL;//防止野指针//////此方法还需要分配空间，而就算=NULL，在下方赋值时本身的child左右节点就可以赋值
    else  
        grand_child = child->right;
    */
    grand_child = child->right;
    child->right = node;
    node->left = grand_child;
    //更新可能改变高度的节点
    updataTree(node);//!!很重要的一点，先要更新下层的叶节点高度才能准确更新上层节点的高度
    updataTree(child);
    return child;
}
//左旋节点函数，与右旋镜像
Treenode* leftTrans(Treenode* node){
    if(node == NULL){//提高稳定性
        printf("err");
        return NULL;
    }
    Treenode* child,*grand_child;
    child = node->right;
    grand_child = child->left;
    //进行左旋
    node->right = grand_child;
    child->left = node;
    //更新节点
    updataTree(node);
    updataTree(child);
    return child;
}
//先左再右函数
Treenode* lRtrans(Treenode* node){
    Treenode* child,*grand_child;
    child = node->left;
    grand_child = child->right;
    //1左旋
    child->left = grand_child;
    //2右旋
    child->right = node;
    //更新节点
    updataTree(node);
    updataTree(child);
    return child;
}
//先右再左函数
Treenode* Rltrans(Treenode* node){
    Treenode* child,*grand_child;
    child = node->right;
    grand_child = child->left;
    //1右旋
    child->right = grand_child;
    //2左旋
    child->left = node;
    //更新节点
    updataTree(node);
    updataTree(child);
    return node;
}
/*
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Treenode{
    int val;
    int hight;
    struct Treenode *left;
    struct Treenode *right;
}Treenode;
//初始化二叉树节点函数
Treenode* newTreenode (int val){
    Treenode* node = malloc(sizeof(Treenode));
    node->val = val;
    node->hight = 0;
    node->left = NULL;//左节点
    node->right = NULL;//右节点
    return node;
}
//获取高度函数
int hight(Treenode* node){
    //如果为空对象，返回-1
    if(node == NULL)
        return -1;
    return node->hight;
}
//更新节点函数
void updataTree (Treenode* node){
    if(node == NULL){
        printf("err");
        return;
    }
    int rN = hight(node->right);
    int rL = hight(node->left);
    //判断左右叶节点的最大高度，赋值= 最大高度 + 1
    if(rL > rN)
        node->hight = rL + 1;
    else
        node->hight = rN + 1;
}
//获取平衡因子函数
int reBanlceNum (Treenode* node){
    if(node == NULL)
        return 0;
    else
        return hight(node->left) - hight(node->right);
}
//右旋节点函数
Treenode* rightTrans(Treenode* node){
    if(node == NULL){//提高稳定性
        printf("err");
        return NULL;
    }
    Treenode* child,*grand_child;//创建旋转中心节点，旋转中心右叶节点
    child = node->left;
    /*
    //如果旋转中心右叶节点为NULL
    if(child->right == NULL)
        grand_child = NULL;//防止野指针//////此方法还需要分配空间，而就算=NULL，在下方赋值时本身的child左右节点就可以赋值
    else  
        grand_child = child->right;
    */
    grand_child = child->right;
    child->right = node;
    node->left = grand_child;
    //更新可能改变高度的节点
    updataTree(node);//!!很重要的一点，先要更新下层的叶节点高度才能准确更新上层节点的高度
    updataTree(child);
    return child;
}
//左旋节点函数，与右旋镜像
Treenode* leftTrans(Treenode* node){
    if(node == NULL){//提高稳定性
        printf("err");
        return NULL;
    }
    Treenode* child,*grand_child;
    child = node->right;
    grand_child = child->left;
    //进行左旋
    node->right = grand_child;
    child->left = node;
    //更新节点
    updataTree(node);
    updataTree(child);
    return child;
}
//先左再右函数
Treenode* lRtrans(Treenode* node){
    Treenode* child,*grand_child;
    child = node->left;
    grand_child = child->right;
    //1左旋
    child->left = grand_child;
    //2右旋
    child->right = node;
    //更新节点
    updataTree(node);
    updataTree(child);
    return child;
}
//先右再左函数
Treenode* Rltrans(Treenode* node){
    Treenode* child,*grand_child;
    child = node->right;
    grand_child = child->left;
    //1右旋
    child->right = grand_child;
    //2左旋
    child->left = node;
    //更新节点
    updataTree(node);
    updataTree(child);
    return node;
}
//添加节点函数////////////AVL
Treenode* addTreenode(Treenode* transfer,int val){
    Treenode* node = malloc(sizeof(Treenode));
    node = transfer;
    //如果目标值节点存在，则直接退出循环
    while(node->val != val){
        if(node->val < val)//right
            node = node->right;
        else//left
            node = node->left;
        if(node == NULL){
            node->val = val;
            //更新高度
            updataTree(node);
            //平衡
            LRfunction(node);
            return node;
        }
    }
  

}
//删除节点函数，分节点度=0，1，2三种情况
Treenode* deleteTreenode(Treenode* transfer,int val){
    Treenode *pre, *cur;
    cur = transfer;
    //先找出相应节点
    while(cur->val == val){
        pre = cur;
        if(cur->val > val)//left
            cur = cur->left;
        else(cur->val < val)//right
            cur = cur->right;
        if(cur == NULL){
            printf("查询不到此元素节点");
            return NULL;
        }
    }//cur保存当前保存着相应的节点值，pre保存相应着相应节点的上一个节点值
    //度为1/0时
    if(cur->left == NULL || cur->right == NULL){
        if(cur->left != NULL){//度为1
            if(pre->right != NULL)//查找pre下端的cur
                pre->right = cur->left;
            else
                pre->left = cur->left;

        }
        else if(cur->right != NULL){
            if(pre->right != NULL)//通过pre确认cur
                pre->right = cur->right;
            else
                pre->left = cue->right;
        }
        else{//度为0
            if(pre->right == cur)
                pre->right = NULL;
            else 
                pre->left = NULL;
        }
    }
    else{//当度为2时
        //中层遍历搜索下一个节点
        Treenode* tmp;//承接变量
        tmp = cur;
        cur = cur->right;
        while(cur != NULL){//深度搜索算法
            cur = cur->left;             
        }
        int tmpNum = cur->val;
        deleteTreenode(transfer,cur->val);//递归再次搜索将要删除的节点
        tmp->val = tmpNum;
    }
        //更新高度
        updataTree(node);
        //平衡
        LRfunction(node);
        return node;
    
}
//通过判断节点的平衡因子，与相应方向(左偏树/右偏树)的平衡因子下的叶节点的平衡因子，来去决定旋转方式
Treenode* LRfunction(Treenode* transfer){
    if(reBanlceNum(transfer) > 1){//左偏树
        if(reBanlceNum(transfer->left) >= 0){//判断左节点的平衡因子
            return rightTrans(transfer);
        }else{
            return lRtrans(transfer);
        }
    }
    if(reBanlceNum(transfer) < -1){//右偏树
        if(reBanlceNum(transfer->right) <= 0){//判断右节点的平衡因子
            return leftTrans(transfer);
        }else{
            return Rltrans(transfer);
        }
    }
    return transfer;//无失衡节点，返回本节点地址
*/
