#include<iostream>
#include<cstdio>
#include<climits>
#include<cstring>
#include<cmath>
using namespace std;

int arr[20][20],brr[20];
char crr[20][20];
int dp[1<<16];
int n;

int rec(int mask)
{
    //cerr<<"M "<<m<<" "<<mask<<" "<<weapon<<endl;
    if(mask==((1<<n)-1))
    {
        return 0;
    }
    if(dp[mask]==-1)
    {
        dp[mask]=INT_MAX;
        for(int i=0; i<n; i++)
        {
            if(((mask)&(1<<i))==0)
            {
                dp[mask]=min(dp[mask],(brr[i]+rec((mask|(1<<i)))));
                for(int j=0; j<n; j++)
                {
                    if((((mask)&(1<<j))!=0)&&(arr[j][i]!=0))
                    {
                        //cerr<<"BB "<<j<<" "<<result<<" "<<(int)ceil(brr[i]/arr[j][i])<<" "<<rec((mask|(1<<i)))<<" "<<mask<<endl;
                        dp[mask]=min(dp[mask],((brr[i]+arr[j][i]-1)/arr[j][i])+rec((mask|(1<<i))));
                    }
                }

            }
        }
    }
    return dp[mask];
}

int main()
{
    int test,i,j,k;
    scanf("%d",&test);
    for(i=0; i<test; i++)
    {
        scanf("%d",&n);
        memset(dp,-1,sizeof dp);
        for(j=0; j<n; j++)
        {
            scanf("%d",&brr[j]);
        }

        for(j=0; j<n; j++)
        {
            getchar();
            for(k=0; k<n; k++)
            {
                scanf("%c",&crr[j][k]);
                arr[j][k]=crr[j][k]-'0';
            }
        }
        printf("Case %d: %d\n",i+1,rec(0));
    }
    return 0;
}
