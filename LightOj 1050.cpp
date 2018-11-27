#include<iostream>
#include<cstdio>
#include<cstring>
#define X 510
using namespace std;

double dp[X][X];
bool mark[X][X];

double rec(int r,int b)
{
    if(r==0 and b==1) return 1.0;
    else if (r<0 or b<=0) return 0;
    double &res=dp[r][b];
    if(mark[r][b]==0)
    {
        mark[r][b]=1;
        res=(r*rec(r-1,b-1)+b*rec(r,b-2))/(r+b);
    }
    return res;
}

int main()
{
    int test,t,r,b;
    scanf("%d",&test);
    memset(mark,0,sizeof mark);
    for(t=1;t<=test;t++)
    {
        scanf("%d%d",&r,&b);
        printf("Case %d: %.9f\n",t,rec(r,b));
    }
    return 0;
}
