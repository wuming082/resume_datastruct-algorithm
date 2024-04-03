#include<math.h>
#include<stdio.h>
int main()
{
  /*  float f = 32;float c;
    c = 5.0/9*(f - 32);
    printf("%.2f\n",c);
    putchar('B');
    putchar('O');
    putchar('Y');
    double area,a,b,c1,s,tep;
    scanf("%lf %lf %lf",&a,&b,&c1);
    s = 1.0/2*(a+b+c1);
    tep = s*(s-a)*(s-b)*(s-c1);
    area = sqrt(tep);
    printf("%.2lf",area);
    float M,t,T,Q;
    scanf("%f %f %f",&M,&t,&T);
    Q = M*(T-t)*4184;
    printf("%.2f",Q);*/
    int a[10] = {1,3,5,2,4,9,6,7,8};
    int b[10];
    int j = 0;
    int sz = sizeof(a)/sizeof(a[0]);
    for(sz = 0;sz>=0;sz--)
    {
        for(j = 0;j<=9;j++){
        if(a[0]<a[sz]){continue;}
        if(a[j]>a[0]){break;
        }
    }
}