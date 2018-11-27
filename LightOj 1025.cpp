#include<iostream>
#include<cstring>
using namespace std;

long long dp[70][70];
char line[70];

long long pal(int i,int j)
{
    if(i>j)
    {
        return 0;
    }
    if(i==j)
    {
        return 1;
    }
    if(dp[i][j]==-1)
    {
        if(line[i]==line[j])
        {
            dp[i][j]=pal(i+1,j)+pal(i,j-1)+1;
        }
        else
        {
            dp[i][j]=(pal(i+1,j)+pal(i,j-1))-pal(i+1,j-1);
        }
    }
    return dp[i][j];
}

int main()
{
    int test,i;
    cin>>test;
    for(i=0;i<test;i++)
    {
        cin>>line;
        memset(dp,-1,sizeof dp);
        cout<< "Case "<<i+1 << ": "<<pal(0,strlen(line)-1)<<endl;
    }
    return 0;
}
