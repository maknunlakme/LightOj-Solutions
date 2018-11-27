#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;

int dp[110][110];
string word;
int rec(int start,int ends)
{
    if(start>=ends)
    {
        return 0;
    }
    if(dp[start][ends]!=-1)
    {
        return dp[start][ends];
    }
    else
    {
        if(word[start]==word[ends])
        {
            dp[start][ends]=rec(start+1,ends-1);
        }
        else
        {
            dp[start][ends]=min(rec(start,ends-1),rec(start+1,ends))+1;
        }
        return dp[start][ends];
    }
}

int main()
{
    //freopen("tempin.txt","r",stdin);
    //freopen("tempout.txt","w",stdout);
    int test,i,j;
    cin>>test;
    for(i=0;i<test;i++)
    {
        cin>>word;
        memset(dp,-1,sizeof dp);
        cout<<"Case "<<i+1<<": "<<rec(0,word.length()-1)<<endl;
    }
    return 0;
}
