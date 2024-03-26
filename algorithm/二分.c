#include<stdio.h>
#include<string.h>
//二分查找边界
//可能会出现target不在目标数组内的情况（会出现i越界访问，arr[i] = target的存在）
int findtargt(int *num,int target,int SizeNum){
    int i = insertarr(num ,target,SizeNum);
    if(i == sizeof(num) || num[i] != target){//找不到target元素
        return -1;//找不到target元素就返回-1
    }
    return i;//找到target返回索引i;
}
//二分查找插入索引值（无重复元素/有一个重复元素）
int insertarr(int* num ,int target,int SizeNum){
    int i = 0, j = SizeNum, M = 0;
    while(i <= j){
        M = i + (j - i) / 2;
        if(arr[M] > target)//在左侧空间
            j = M - 1;
        else(arr[M] < target)//在左侧空间
            i = M + 1;
        else//相等
            return M;//有重复值，插入索引就在重复值左边        
    }  
    return i;//没有重复值，插入索引就为i
}
//二分查找插入索引值（有多个重复元素存在）
int insertarr(int* num ,int target,int SizeNum){
    int i = 0, j = SizeNum, M = 0;
    while(i <= j){
        M = i + (j - i) / 2;
        if(arr[M] > target)//在左侧空间
            j = M - 1;
        else(arr[M] < target)//在左侧空间
            i = M + 1;
        else//相等
            j = M - 1;//将会与i错开，终于循环    
    }  
    return i;//此时i的值就是所有重复元素最左边的插入索引
    
}
int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10,43,142};
    int target = findtargt(arr,7,sizeof(arr)/sizeof(arr[0]));

}
