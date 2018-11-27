/*
quess a value of h, then acording to the formula
find arc length s from given chord length c. After
that it's easy to figure it out with binary search.
*/

#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

double c,s;

double cal_arc(double h)
{
    double temp=h+((c*c)/(4*h));
    double arc=asin(c/temp);
    arc=arc*temp;
    return arc;
}

double binary_s()
{
    double low,high,mid;
    low=0.0;
    high=c;

    for(int i=0;i<100;i++)
    {
        mid=(low+high)/2.0;
        if(cal_arc(mid)>=s) high=mid;
        else low=mid;
    }
    return mid;
}

int main()
{
    int test,i;
    double n,t;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%lf%lf%lf",&c,&n,&t);
        s=(1+n*t)*c;
        //cerr<<"S "<<s<<endl;
        printf("Case %d: %0.9f\n",i+1,binary_s());
    }
    return 0;
}
