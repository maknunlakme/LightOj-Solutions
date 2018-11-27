#include<iostream>
#include<cstdio>
#include<cstring>
#define X 110
using namespace std;

int dp[X][X],arr[X];
int n;

int rec(int start,int ends)
{
    //cerr<<"TT "<<start<<" "<<ends<<endl;
    if(start<0 or ends>=n or start>ends) return 0;
    int &res=dp[start][ends];
    int a=0,b=0;
    if(res==-1)
    {
        if(start==ends)
        {
            res=1;
        }
        else
        {
            res=rec(start+1,ends)+1;
            for(int i=start+1; i<=ends; i++)
            {
                if(arr[start]==arr[i])
                {
                    res=min(res,rec(start,i-1)+rec(i+1,ends));
                    //cerr<<"RR "<<start<<" "<<i<<" "<<res<<endl;
                }
            }
        }
    }
    //cerr<<"SS "<<start<<" "<<ends<<" "<<res<<endl;
    return res;
}

int main()
{
    int test,i,j;
    scanf("%d",&test);
    for(i=0; i<test; i++)
    {
        scanf("%d",&n);
        memset(dp,-1,sizeof dp);
        for(j=0; j<n; j++)
        {
            scanf("%d",&arr[j]);
        }
        printf("Case %d: %d\n",i+1,rec(0,n-1));
    }
    return 0;
}
