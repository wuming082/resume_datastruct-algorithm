#include <stdio.h>
#include <string.h>
struct BOOk{
    int age;
    int name_id;
    char name[100];
}book = {23,2311611051,"back the future"};
int main(){
    //创建结构体变量
    struct BOOk new;
    new.age = 42;
    strcpy(new.name,"hello world!");
    printf("%s",new.name);
    return 0;
}