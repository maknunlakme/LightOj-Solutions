#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int a,b;

double stadium(double n)
{
    double height=n*a;
    double width=n*b;
    double square=height*2;
    double radius=(sqrt((height*height)+(width*width)))/2;
    double theta=2*asin(width/(2*radius));
    double segment=(radius*theta);
    double area=square+(segment*2);
    return area;
}

double binary_s()
{
    double low,high,mid;
    low=0.0;
    high=400;
    for(int i=0;i<100;i++)
    {
        mid=(low+high)/2.0;
        if(stadium(mid)>=400) high=mid;
        else low=mid;
    }
    return mid;
}

int main()
{
    int test,i;
    double answer;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d : %d",&a,&b);
        answer=binary_s();
        printf("Case %d: %0.9f %0.9f\n",i+1,a*answer,b*answer);
    }
    return 0;
}
