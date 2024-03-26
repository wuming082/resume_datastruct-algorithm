#include<stdio.h>
void insert (int *arr ,int location , int Long){
//数组删除 Long数组长度
    for(int i = location ; i < Long ; i++){
        arr[i] = arr[i + 1];
    }
}
//打印数组元素
void printArr (int *arr,int Long){
    for(int i = 0 ; i < Long ; i++){
        printf("%d",arr[i]);
    }
}
//数组删除 long数组长度
void addArr(int *arr ,int location , int Long , int addNum){
    for(int i = Long - 1 ; i > location ; i--){
        arr[i] = arr[i - 1];
    }
    arr[location] = addNum;
}
int main (){
    int arr[] = {1,2,3,4,5,6,7,8};
    //addArr(arr,4,8,1);
    //insert(arr,2,8);
    printArr(arr,8);
    return 0;
}