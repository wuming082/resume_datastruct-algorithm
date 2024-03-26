#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
    int input;
    scanf("%d",&input);
    for (int i = 0; i < input;i++)
    {
        system("clear");
        sleep(4);
        printf("%d",i);
        sleep(4);
    }
    return 0;
}