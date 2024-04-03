#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//打印数组
void printfarr(int arr[],int size){
    for(int i = 0 ; i < size ; i++){
        printf("%d ",arr[i]);
    }
}
//选择排序算法
int* selsesort(int* arr,int SizeNum){//SizeNum 为数组的元素数量
    int i = 0 , j = 0 ;
    for(i = 0 ; i < SizeNum - 1;i++){
        int k = i;
        for(j = i + 1; j < SizeNum;j++){
            if(arr[j] < arr[k])
                k = j;//遍历找到最小元素（因为此轮遍历是在上一层遍历之上的，所以没有任何一个元素能比上一轮遍历的最小元素还要小）
        }
        int tmp = arr[j];//与未遍历数组的首元素交换最小元素
        arr[j] = arr[k];    
        arr[k] = tmp;
    }
    return arr;
}
//冒泡排序//算法优化
void bobosort (){
    bool flag;
    int arr[10] = {1,4,10,4,2,4,5,6,4,14};
    int i = 0 , j = 0 ;
    for(i = 0 ; i < 9 ; i++){
        for(j =  0 ; j < 9 - i ; j++){
            if(arr[j] > arr[j+1]){
                int tmp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = tmp;
                flag = true;
            }//如果一趟遍历，都不需要进行排序，则标记
        }
        if(!flag){
            break;
        }
    }
    for(int k = 0 ; k < 10 ; k++){
        printf("%d ",arr[k]);
    }
}
//插入排序思想
void insertsort(int nums[],int size){
    for(int i = 1 ; i < size ; i++){//只需要有n -1次遍历，因为是从第二元素开始遍历到末尾。
        int base = nums[i];
        int j = i - 1;
        while(j >= 0 && nums[j] > base){
            nums[j + 1] = nums[j];
            j--;
        }//空位空出，插入元素数值
        nums[j + 1] = base;//因为循环时多自减了1；
    }
}
/*
//插入排序
void insetsort(){
    int arr[10] = {1,5,10,6,4,7,2,23,12,18};
    int size = sizeof(arr)/sizeof(arr[0]);
    int base;
    for(int i = 1 ; i < size; i++){
        int j = i - 1,base = arr[i];
        while(arr[j] > base && j >= 0){
            arr[j + 1] = arr[j];//将目标元素相后移动一位(移动到插入元素的初始位置)
            j--;
        }
        arr[j + 1] = base;//此节点因为在跳出循环前又被自减，所以用j + 1
    }
    for(int k = 0 ; k < size ;k++){
        printf("%d ",arr[k]);
    }
}
*/
//快速排序函数
void swap(int nums[],int i , int j){
    //交换元素
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}
//哨兵划分思想
int quicksort(int nums[],int left,int right){
    int i = left;
    int j = right; 
    int base = nums[left];
    while(i < j){
        while(i < j && nums[j] >= base){
            j--;
        }
        while(i < j && nums[i] <= base){
            i++;
        }
        //i索引的元素和j索引的元素交换
        swap(nums,i,j);
    }
    //将i的元素与最左端的元素调换
    swap(nums,left,i);
    return i;
}
int main(){
    //bobosort();
    //printf("\n");
    //insetsort();
    int arr[] = {1,4,1,3,5,1,5,7,2,1,60,53,12,64,13,76,34,65,5,34,54,576,2435,547,2342526,53,65,234,65,23,653,235,123235,346,235,346,2352135,5,2135,235,33246,344,134};
    insertsort(arr,sizeof(arr)/sizeof(arr[0]));
    printfarr(arr,sizeof(arr)/sizeof(arr[0]));

}
/*
//插入排序思想
void insert(){
    //size数组元素数量 
    for(int i = 1 ; i < size ;i++){
        int base = arr[i];
        j = i - 1;
        while(arr[j] > base && j >= 0){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = base;
    }
}
*/
