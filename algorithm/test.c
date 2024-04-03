#include<stdio.h>
void testprintf(int *num){
    int Num = sizeof(num)/sizeof(num[0]);
    printf("%d",Num);
}
int main(){
    int arr[] = {1,2,3,4,5,6};
    int Num = sizeof(arr)/sizeof(arr[0]);
    printf("%d\n",Num);
    testprintf(arr);
}