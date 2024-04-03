#include<stdio.h>
//二分递归分治思想
int dfs(int nums[],int target , int left, int right){
    if(left > right){
        return -1;//找不到目标元素，直接返回-1
    }
    int m = left + (right - left) / 2;//求出中值
    if(nums[m] > target){
        return dfs(nums,target,left,m - 1);
    }else if(nums[m] < target){
        return dfs(nums,target,m + 1,right);
    }else{
        return m;
    }
} 
//二分查找函数
int binaryserch(int nums[], int target, int Numsize){
    return dfs(nums,target,0,Numsize - 1);//调用递归传入左右界限
}
int main()
{
    int a,b,con;
    a = 10, b = 20, con = 99;
    int count , i , day;
    while(count < con){
        if(i == 6){
            count += b;
            i++;
        }
        else if(i == 7){
            count += b;
            i = 0;
        }else{
            count += a;
            i++;
        }
        day++;
    }
    printf("%d",day);
    return 0;
}