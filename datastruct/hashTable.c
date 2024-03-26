#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
#define capacity 100
//承接遍历结果结构体
typedef struct Mapset{
    int len;
    void *set;
}Mapset;
//哈希表算法函数
int Hashmapkey(int Num)
{
    if(Num < capacity)
        printf("错误! key值过小!\n");
    else
        return Num % capacity;
}
//键值对结构体
typedef struct pairs{
    int key;//用于存放key值
    char *val;
}pairs;
//基于数组构造哈希表7
typedef struct ArrayHashmap{
    pairs* buckets[capacity];
}ArrayHashmap;
//初始化哈希表数组
ArrayHashmap* newArrayHashmap()
{
    ArrayHashmap* node = malloc(sizeof(ArrayHashmap));
    return node;
}
//删除哈希表数组
void delArrayHashmap(ArrayHashmap* node)
{
    for(int i = 0 ; i < capacity ; i++)
    {
        if(node->buckets[i] != NULL){
            free(node->buckets[i]->val);
            free(node->buckets[i]);
        }
    }
}
//遍历键值对函数//////////////////////////////////!!重点！！//////////////////////
void pairset(ArrayHashmap* transfer,Mapset* set)
{
    //通过遍历查看哈希表内的所有元素大小
    int totol = 0 ,index = 0;//index用于下方不连续赋值循环当中////////////////////
    for(int i = 0 ; i < capacity ; i++)
    {
        if(transfer->buckets[i] != NULL)
            totol++;
    }
    //创建承接哈希表元素的结构体
    pairs* node = (pairs*)malloc(sizeof(pairs) * totol);
    for(int i = 0 ; i < capacity ; i++)
    {
        if(transfer->buckets[i] != NULL)//node[index].key虽然创建的为结构体变量，但引用时还是为(.)
        {
            node[index].key = transfer->buckets[i]->key;
            node[index].val = malloc(strlen(transfer->buckets[i]->val) + 1);//要分配给相应能够承接val元素空间大小的空间
            strcpy(node[index].val,transfer->buckets[i]->val);
            index++;
        }
    }
    set->set = node;
    set->len = totol;
}
/////////////////////////////////////////！！重点！！////////////////////////////
//添加哈希表元素函数
void put (ArrayHashmap* transfer,int key,const char *val)
{
    pairs* node = malloc(sizeof(pairs));
    node->key = key;//本身传入的数据为固定不可变数据，所以先分配给val相应空间
    node->val = malloc(strlen(val) + 1);
    strcpy(node->val,val);
    int Hkey = Hashmapkey(key);
    transfer->buckets[Hkey] = node;
}

