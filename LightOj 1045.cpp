#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#define X 1000000
using namespace std;
int main()
{
    int test,i,a,b;
    double n[X+10];
    n[0]=0.0;
    for(i=1;i<=X;i++)
    {
        n[i]=log(i)+n[i-1];
        //cout<<f[i]<<endl;
    }
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d%d",&a,&b);
        printf("Case %d: %.0f\n",i+1,floor(n[a]/(n[b]-n[b-1]))+1);
    }
    return 0;
}
