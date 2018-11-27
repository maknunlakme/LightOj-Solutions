#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;

string a,b;
int dp[40][40];
long long dp2[40][40];

int main()
{
    //freopen("tempin.txt","r",stdin);
    //freopen("tempout.txt","w",stdout);
    int test,i,j,k,lengtha,lengthb;
    cin>>test;
    for(i=0; i<test; i++)
    {
        cin>>a>>b;
        lengtha=a.length();
        lengthb=b.length();
        for(j=0; j<=lengtha; j++)
        {
            for(k=0; k<=lengthb; k++)
            {
                if(j==0)
                {
                    dp[j][k]=k;
                }
                else if(k==0)
                {
                    dp[j][k]=j;
                }
                else if(a[j-1]==b[k-1])
                {
                    dp[j][k]=dp[j-1][k-1]+1;
                }
                else
                {
                    dp[j][k]=min(dp[j-1][k],dp[j][k-1])+1;
                }
            }
        }
        for(j=0; j<=lengtha; j++)
        {
            for(k=0; k<=lengthb; k++)
            {
                if(j==0||k==0)
                {
                    dp2[j][k]=1;
                }
                else if(a[j-1]==b[k-1])
                {
                    dp2[j][k]=dp2[j-1][k-1];
                }
                else if(dp[j][k-1]<dp[j-1][k])
                {
                    dp2[j][k]=dp2[j][k-1];
                }
                else if(dp[j][k-1]>dp[j-1][k])
                {
                    dp2[j][k]=dp2[j-1][k];
                }
                else
                {
                    dp2[j][k]=dp2[j-1][k]+dp2[j][k-1];
                }
            }
        }
        cout<<"Case "<<i+1<<": "<<dp[lengtha][lengthb]<<" "<<dp2[lengtha][lengthb]<<endl;
    }
    return 0;
}
