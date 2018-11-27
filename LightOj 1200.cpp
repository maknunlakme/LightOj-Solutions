#include<iostream>
#include<cstdio>
#include<cstring>
#define X 110
using namespace std;

int price[X],need[X],weight[X];
int dp[X][11000];

int rec(int pos,int left)
{
    //cerr<<"RR "<<pos<<" "<<left<<endl;
    if(left<=0 or pos<0) return 0;
    int &res=dp[pos][left];
    if(res==-1)
    {
        res=rec(pos-1,left);
        if(left-weight[pos]>=0)
        {
            res=max(res,rec(pos,left-weight[pos])+price[pos]);
            res=max(res,rec(pos-1,left-weight[pos])+price[pos]);
        }
    }
    return res;
}

int main()
{
    int test,n,w,t,i,must;
    bool possible;
    scanf("%d",&test);
    for(t=1;t<=test;t++)
    {
        scanf("%d%d",&n,&w);
        memset(dp,-1,sizeof dp);
        must=0;
        possible=true;
        for(i=0;i<n;i++)
        {
            scanf("%d%d%d",&price[i],&need[i],&weight[i]);
            must+=need[i]*weight[i];
        }
        //cerr<<"WWW "<<must<<" "<<w<<endl;
        if(must>w) possible=false;
        else w-=must;
        if(possible==true)
        {
            printf("Case %d: %d\n",t,rec(n-1,w));
        }
        else
        {
            printf("Case %d: Impossible\n",t);
        }
    }
    return 0;
}
