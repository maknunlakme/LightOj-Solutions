#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;

int dp[60][60][60];

int main()
{
    //freopen("tempin.txt","r",stdin);
    //freopen("tempout.txt","w",stdout);
    int test,i,j,k,l,lengtha,lengthb,lengthc,maxi;
    string a,b,c;
    cin>>test;
    for(l=0;l<test;l++)
    {
        cin>>a>>b>>c;
        lengtha=a.length();
        lengthb=b.length();
        lengthc=c.length();
        maxi=0;
        memset(dp,0,sizeof dp);
        for(i=1;i<lengtha+1;i++)
        {
            for(j=1;j<lengthb+1;j++)
            {
                for(k=1;k<lengthc+1;k++)
                {
                    if(a[i-1]==b[j-1]&&a[i-1]==c[k-1])
                    {
                        dp[i][j][k]=dp[i-1][j-1][k-1]+1;
                    }
                    else
                    {
                        maxi=max(dp[i-1][j][k],dp[i][j-1][k]);
                        dp[i][j][k]=max(dp[i][j][k-1],maxi);
                    }
                }
            }
        }
        cout<<"Case "<<l+1<<": "<<dp[lengtha][lengthb][lengthc]<<endl;
    }
    return 0;
}
