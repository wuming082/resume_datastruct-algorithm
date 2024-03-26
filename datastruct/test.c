#include<stdio.h>
int main()
{

    int arr[5] = {0,0,0,0,0};
    int XX = 0;
    arr[XX++] = 1;
    printf("%d,%d",arr[0],XX);
    return 0;
}