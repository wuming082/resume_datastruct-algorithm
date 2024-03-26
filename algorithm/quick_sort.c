#include<stdio.h>
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