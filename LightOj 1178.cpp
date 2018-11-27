#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

double a,b,c,d,e,s,triange_area,height,real_area;

double area()
{
    e=fabs(a-c);
    s=(b+d+e)/2;
    triange_area=sqrt(s*(s-b)*(s-d)*(s-e));
    height=(triange_area*2)/e;
    real_area=((a+c)/2)*height;
    return real_area;
}

int main()
{
    int test,i;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
        printf("Case %d: %0.9f\n",i+1,area());
    }
    return 0;
}
