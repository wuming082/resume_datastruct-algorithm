//桶排序
#include<stdio.h>
#include<stdlib.h>
#define ARRAY_SIZE 100
/////////////////////////////桶排序////err/////////////
//选择排序/交换
void swap(float nums[],int i , int j){
    float tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = nums[i];
}
void selectsort (float nums[]){
    int j = 0;
    for(int i = 0 ; i < ARRAY_SIZE - 1 ; i++){
        int k = i;
        for(j = i + 1 ; j < ARRAY_SIZE; j++){
            if(nums[k] > nums[j])
                k = j;
        }
        swap(nums,k,j);
    }
}
//桶排序算法思想
void bucktsort(float nums[],int numSize){
    //分配 numSize/2个桶 每个桶可以放ARRAY_SIZE个元素
    int k = numSize / 2;
    float** buckt = calloc(k,sizeof(float*));
    //给每个桶内分配数组
    for(int i = 0 ; i < k ; i++){
        buckt[i] = calloc(ARRAY_SIZE,sizeof(float));
    } 
    //1.将主数组的相关元素分配到相应数组当中
    for(int i = 0 ; i < numSize ; i++){
        //判断当前主数组元素的元素归属桶[0-k-1]（区间缩放）
        int bucktsortNum = nums[i] * k;
        //判断当前桶的元素个数，将索引值索引到空位
        int j = 0 ;
        while(buckt[bucktsortNum][j] > 0){
            j++;
        }
        //放到相应的桶当中
        buckt[bucktsortNum][j] = nums[i];
    }
    //2将所有的桶内进行快速排序/选择排序
    for(int i = 0 ; i < k ; i++){
        selectsort(buckt[i]);
    }
    //3将所有的桶放入目标数组
    int count = 0;
    for(int i = 0 ; i < k ; i++){
        for(int j = 0 ; j < ARRAY_SIZE ; j++){
            if(buckt[i][j] > 0){
                nums[count++] = buckt[i][j];
            }
        }
    }
}
int main(){
    float arr[] = {0.99,0.34,0.67,0.94,0.23,0.12,0.659,0.29,0.64,0.67,0.86,0.52,0.67};
    bucktsort(arr,sizeof(arr)/sizeof(arr[0]));
    for(int i = 0 ; i < sizeof(arr)/sizeof(arr[0]); i++){
        printf("%f ",arr[i]);
    }
    return 0;
}