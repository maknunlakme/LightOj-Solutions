#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

double x,y,c;

double cal_road(double w)
{
    double p=sqrt((y*y)-(w*w));
    double q=sqrt((x*x)-(w*w));
    double height=(p*q)/(p+q);
    return height;
}
double binary_s()
{
    double low,high,mid;
    low=0.0;
    high=min(x,y);
    for(int i=0;i<100;i++)
    {
        mid=(low+high)/2.0;
        //cerr<<"PPP "<<cal_road(mid)<<" "<<c<<endl;
        if(cal_road(mid)<c) high=mid;
        else low=mid;
    }
    return mid;
}

int main()
{
    int test;
    scanf("%d",&test);
    for(int i=0;i<test;i++)
    {
        scanf("%lf%lf%lf",&x,&y,&c);
        printf("Case %d: %0.9f\n",i+1,binary_s());
    }
    return 0;
}
