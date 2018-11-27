#include<iostream>
#include<cmath>
#include<cstdio>
#include<iomanip>
#define PI 3.14159265
using namespace std;
int main()
{
    //freopen("tempin.txt","r",stdin);
    //freopen("tempout.txt","w",stdout);
    int test,i;
    double R,n,r,theta;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%lf%lf",&R,&n);
        theta=sin(PI/n);
        r=(R*theta)/(1+theta);
        cout<<fixed<<setprecision(6)<<"Case "<<i+1<<": "<<r<<endl;
    }
    return 0;
}
