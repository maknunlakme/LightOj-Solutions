#include<iostream>
#include<cstdio>
#include<cstring>
#define check(x,y) (x&(1<<y))
#define on(x,y) (x|(1<<y))
#define X 16
using namespace std;

int mat[X][X];
int dp[X][1<<X];
int n;

int rec(int pos,int mask)
{
    if(pos==n) return 0;
    int &ans=dp[pos][mask];
    if(ans==-1)
    {
        ans=1000000000;
        int i,j,temp;
        for(i=0;i<n;i++)
        {
            temp=0;
            if(check(mask,i)==0)
            {
                //cerr<<"IIIII"<<endl;
                for(j=0;j<n;j++)
                {
                    //cerr<<"RR "<<j<<" "<<(1<<j)<<" "<<mask<<" "<<check(mask,j)<<endl;
                    if(check(mask,j))
                    {
                        temp+=mat[i][j];
                        //cerr<<"JJ "<<j<<" "<<temp<<endl;
                    }
                }
                //cerr<<"RR "<<ans<<" "<<pos<<" "<<i<<" "<<mat[i][i]<<" "<<mask<<" "<<temp<<endl;
                ans=min(ans,rec(pos+1,on(mask,i))+mat[i][i]+temp);
                //cerr<<"PPP "<<ans<<endl;
            }
        }
    }
    return ans;
}


int main()
{
    int test,t,i,j;
    scanf("%d",&test);
    for(t=1;t<=test;t++)
    {
        scanf("%d",&n);
        memset(dp,-1,sizeof dp);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&mat[i][j]);
            }
        }
        printf("Case %d: %d\n",t,rec(0,0));
    }
    return 0;
}
