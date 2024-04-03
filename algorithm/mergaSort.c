#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//打印数组
void printfarr(int nums[],int size){
    for(int i = 0 ; i < size ; i++){
        printf("%d",nums[i]);
    }
}
void merga(int *nums,int left,int mid ,int right){
    //开始合并元素/排序
    //标记开始索引变量
    int i = left , j = mid + 1;//i为左数组起点，j为右数组起点
    int tmpSize = right - left + 1;//此元素大小
    int *tmp = malloc(sizeof(int) * tmpSize);
    int k = 0 ;//新建立空间数组的投标索引值
    //如果左右子数组都存在元素
    while(i <= mid && j <= right){
        //通过判断大小放入排序后的元素
        if(nums[i] <= nums[j]){
            tmp[k++] = nums[i++];//设置为从左到右小->大排序方式
        }else{
            tmp[k++] = nums[j++];
        }
    }
    while(i <= mid){//将左数组放置到临时数组当中
        tmp[k++] = nums[i++];
    }
    while(j <= right){//将右数组放置到临时数组当中
        tmp[k++] = nums[j++];
    }
    //将临时数组内存转移到主数组
    for(k = 0 ; k < tmpSize ; k++){
       nums[left + k] = tmp[k];
    }
    ////////////////////////////////////////////
    //k = 0;
    //for(int con = left; con< right; con++){
    //    nums[con] = tmp[k++];
    //}
    /////////////////////////////////////////////
    //释放内存
    free(tmp);
}
//归并排序 递归算法
void mergaSort(int *nums,int left,int right){//没有中值，在递归中计算
    if(left >= right){//如果数组元素数量为一，则不再进行递归
        return;
    }
    //计算中值
    int mid = (left + right) / 2;
    //向左数组递归
    mergaSort(nums,left,mid);
    //向右数组递归 
    mergaSort(nums,mid + 1,right);
    //最后处理单位节点数组元素，进行排序
    merga(nums,left,mid,right);
}
int main(){
    string a = "hello";
    printf("%cg vv c",a);
    int arr[] = {4,1,4,1,532,52,654,653,234,564,234,65,5,43,64,13,634,65,13,454};
    mergaSort(arr,0,sizeof(arr)/sizeof(arr[0]));
    for(int i = 0 ; i < sizeof(arr)/sizeof(arr[0]); i++){
        printf("%d ",arr[i]);
    }
    return 0;
}