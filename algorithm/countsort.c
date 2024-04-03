#include<stdio.h>
#include<stdlib.h>
//countsort
void countsort(int nums[],int size){
    //1,记录最大元素值
    int m;//记录最大值变量
    for(int i = 0 ; i < size ; i++){
        if(nums[i] > m){
            m = nums[i];
        }
    }
    //2,开始将数组元素记录到相应的计数数组当中
    int* count = calloc(m + 1 ,sizeof(int));
    for(int i = 0 ; i < size ; i++){
        count[nums[i]]++;//相应的记录元素自增;
    }
    for(int i = 0 ; i< m+1 ; i++){
        printf("%d ",count[i]);
    }
}