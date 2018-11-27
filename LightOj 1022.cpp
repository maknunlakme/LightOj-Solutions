#include<iostream>
#include<cstdio>
#include<cmath>
#define pi 2*acos(0.0)
using namespace std;
int main()
{
    int test,i;
    double n,answer;
    //cout<<pi<<endl;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%lf",&n);
        answer=(n*n)*(4-pi);
        //cout<<(n*n)*(4-pi)<<endl;
        printf("Case %d: %0.2f\n",i+1,answer);
    }
    return 0;
}
