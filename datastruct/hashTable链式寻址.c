#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//键值对结构体
typedef struct pairs{
    int key;
    char* val;
}pairs;
//链表结构体
typedef struct Linknode{
    pairs *node;
    struct Linknode* next;
}Linknode;
//初始化链表结构体函数
Linknode* newLinknode()
{
    Linknode* node = malloc(sizeof(Linknode));
    node->node = NULL;
    node->next = NULL;
    return node;
}

//链式哈希表结构体
typedef struct nodeHash{
    int size;
    int capacity;
    Linknode **buckets;
    double extendNum;
    int woringK;
}nodeHash;
//初始化链式哈希表结构体函数
nodeHash* newnodeHash()
{
    nodeHash* node = malloc(sizeof(nodeHash));
    node->size = 0;
    node->capacity = 100;
    node->extendNum =2;
    node->woringK = 2.0/3.0;
    node->buckets = malloc(sizeof(Linknode) * node->capacity);
    return node;
}
//查看哈希表元素大小函数
int checkSizeHash(nodeHash* transfer)
{
    return transfer->size;
}
//哈希值计算函数
int nodeHashNum(nodeHash* transfer,int key)
{
    return key % transfer->capacity;
}
//添加哈希表元素函数
void put(nodeHash* transfer,int key,char * val)
{
    //创建哈希桶节点
    Linknode* node = newLinknode();
    //创建键值对
    pairs* pair = malloc(sizeof(pairs));
    pair->val = malloc(strlen(val) + 1);//分配内存
    strcpy(pair->val,val);
    //键值对和桶节点连接
    node->node = pair;
    //创建桶索引变量
    int bucketsNum = nodeHashNum(transfer,key);
    //将元素放入桶索引
    //检查该索引处是否已经有元素占用
    if(transfer->buckets[bucketsNum] == NULL){
        pair->key = key;
        transfer->buckets[bucketsNum] = node;
    }
    else{
        pair->key = key;
        //将桶节点与键值节点链断开，将新键值节点链接
        node->next = transfer->buckets[bucketsNum];
        transfer->buckets[bucketsNum] = node;
    }
    transfer->size++;
}
//哈希表查找元素
void chackHashVal(nodeHash* transfer,int key)
{
    if(transfer->buckets[nodeHashNum(transfer,key)] == NULL)
        printf("键值key:%d,未有相连接的字符串！",key);
    else{
        
        if(transfer->buckets[nodeHashNum(transfer,key)]->node->key == key)
            printf("%s",transfer->buckets[nodeHashNum(transfer,key)]->node->val);
        else{
            Linknode* cure = malloc(sizeof(Linknode));
            cure = transfer->buckets[nodeHashNum(transfer,key)];
            while(transfer->buckets[nodeHashNum(transfer,key)]->node->key != key)
                {
                    cure = cure->next;
                    if(cure->node->key == key)
                        printf("%s",cure->node->val);
                }   
        }
    }
}
int main()
{
    nodeHash* node = newnodeHash();
    char* a ="nihaoma";
    char* b ="hello world";
    char* H ="dreamsky";
    char* r ="lll";
    char* R ="nice to meet you";
    put(node,19293,a);
    put(node,19811,R);
    put(node,19341,H);
    put(node,48104,r);
    put(node,19911,b);
    chackHashVal(node,19934);
    chackHashVal(node,19811);
    return 0;
}