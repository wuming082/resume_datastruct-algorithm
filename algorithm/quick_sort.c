#include<stdio.h>
//打印数组
void printfarr(int arr[],int size){
    for(int i = 0 ; i < size ; i++){
        printf("%d ",arr[i]);
    }
}
//选取中位数函数
int findmid(int nums[],int left,int mid,int right){ 
    int l = nums[left] , m = nums[mid] , r = nums[right];
    if(l >= m && r >= l || l >= r && m >= l)
        return left;//left为中位数
    else if(m >= l && r >= m || m >= r && l >= m)
        return mid;//mid为中位数
    else 
        return right;//right为中位数 
}
//快速排序函数
void swap(int nums[],int i , int j){
    //交换元素
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}
/*
//哨兵划分思想 旧版
int partition(int nums[],int left,int right){
    int i = left;
    int j = right; 
    int base = nums[left];
    while(i < j){
        while(i < j && nums[j] >= base){//从右向左寻找小于基准数的首个元素
            j--;
        }
        while(i < j && nums[i] <= base){//从左向右寻找大于基准数的首个元素
            i++;
        }
        //i索引的元素和j索引的元素交换
        swap(nums,i,j);
    }
    //将i的元素与最左端的元素调换
    swap(nums,left,i);
    return i;
}
*/
//哨兵划分思想 基准值优化版
int partition(int nums[],int left,int right){
    int mid = findmid(nums,left,(left + right) / 2 , right);//返回基准值（中位数）
    swap(nums,left,mid);//将所选目标基准值与left交换
    int i = left;
    int j = right; 
    int base = nums[left];
    while(i < j){
        while(i < j && nums[j] >= base){//从右向左寻找小于基准数的首个元素
            j--;
        }
        while(i < j && nums[i] <= base){//从左向右寻找大于基准数的首个元素
            i++;
        }
        //i索引的元素和j索引的元素交换
        swap(nums,i,j);
    }
    //将i的元素与最左端的元素调换
    swap(nums,left,i);
    return i;
}
//快速排序函数 原版
void quicksort (int nums[],int left ,int right){
    //数组长度为1时终止递归
    if(left >= right){
        return;
    }
    int point = partition(nums,left ,right);
    //左数组传入
    quicksort(nums,left,point - 1);
    //右数组传入
    quicksort(nums,point + 1,right);
}
int main(){
    int arr[] = {1,4,1,3,5,1,5,7,2,1,60,53,12,64,13,76,34,65,5,34,54,576,2435,547,2342526,53,65,234,65,23,653,235,123235,346,235,346,2352135,5,2135,235,33246,344,134};
    quicksort(arr,0,sizeof(arr)/sizeof(arr[0]) - 1);
    printfarr(arr,sizeof(arr)/sizeof(arr[0]));
}