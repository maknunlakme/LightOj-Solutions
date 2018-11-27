#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#define X 110
using namespace std;

int dp[X][X];
string ans[X][X];
int lengtha,lengthb;
char a[X],b[X];
int lcs_lexico()
{
    int i,j;
    lengtha=strlen(a);
    lengthb=strlen(b);
    for(i=0;i<=lengtha+2;i++)
    {
        dp[i][0]=0;
        ans[i][0]="";
    }
    for(i=0;i<=lengthb+2;i++)
    {
        dp[0][i]=0;
        ans[0][i]="";
    }
    for(i=1; i<=lengtha; i++)
    {
        for(j=1; j<=lengthb; j++)
        {
            if(a[i-1]==b[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
                ans[i][j]=ans[i-1][j-1]+a[i-1];
                //cerr<<i<<" "<<j<<" "<<ans[i][j]<<endl;
            }
            else if(dp[i-1][j]>dp[i][j-1])
            {
                dp[i][j]=dp[i-1][j];
                ans[i][j]=ans[i-1][j];
            }
            else if(dp[i][j-1]>dp[i-1][j])
            {
                dp[i][j]=dp[i][j-1];
                ans[i][j]=ans[i][j-1];
            }
            else
            {
                dp[i][j]=dp[i-1][j];
                ans[i][j]=min(ans[i-1][j],ans[i][j-1]);
            }
        }
    }
}



int main()
{
    int test,i,j;
    scanf("%d",&test);
    for(i=0; i<test; i++)
    {
        scanf("%s%s",a,b);
        lcs_lexico();
        if(dp[lengtha][lengthb]==0)
        {
            printf("Case %d: :(\n",i+1);
            //cout<<"Case "<<i+1<<": :("<<endl;
        }
        else
        {
            //printf("Case %d: %s\n",i+1,ans[lengtha][lengthb].c_str());
            cout<<"Case "<<i+1<<": "<<ans[lengtha][lengthb]<<endl;
        }
    }
    return 0;
}
