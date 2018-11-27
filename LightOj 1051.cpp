#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

string line;
int dp[60][10][10];

int rec(int pos,int vow,int cons)
{
    //cout<<pos<<" "<<vow<<" "<<cons<<endl;
    if(dp[pos][vow][cons]!=-1)
    {
        return dp[pos][vow][cons];
    }
    if(vow==3||cons==5)
    {
        return 1;
    }
    if(pos>=line.length())
    {
        return 2;
    }
    if(line[pos]=='A'||line[pos]=='E'||line[pos]=='I'||line[pos]=='O'||line[pos]=='U')
    {
        dp[pos][vow][cons]=rec(pos+1,vow+1,0);
    }
    else if(line[pos]=='?')
    {
        dp[pos][vow][cons]=(rec(pos+1,vow+1,0)|rec(pos+1,0,cons+1));
    }
    else
    {
        dp[pos][vow][cons]=rec(pos+1,0,cons+1);
    }
    return dp[pos][vow][cons];
}
int main()
{
    //freopen("tempin.txt","r",stdin);
    //freopen("tempout.txt","w",stdout);
    int test,i,answer;
    cin>>test;
    for(i=0;i<test;i++)
    {
        cin>>line;
        memset(dp,-1,sizeof dp);
        answer=rec(0,0,0);
        if(answer==1)
        {
            cout<<"Case "<<i+1<<": BAD"<<endl;
        }
        else if(answer==2)
        {
            cout<<"Case "<<i+1<<": GOOD"<<endl;
        }
        else
        {
            cout<<"Case "<<i+1<<": MIXED"<<endl;
        }
    }
    return 0;
}
