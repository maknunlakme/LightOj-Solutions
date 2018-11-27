#include<iostream>
#include<cstdio>
#include<cstring>
#define on(x,y) (x|(1<<y))
#define check(x,y) (x&(1<<y))
#define X 17
using namespace std;

char line[X+5];
long long dp[X+5][1<<X];
int n,base,k;

int cal(int left,int one)
{
    int temp=left*base;
    if(line[one]>='0' and line[one]<='9')
    {
        temp+=line[one]-'0';
    }
    else if(line[one]>='A' and line[one]<='F')
    {
        temp+=10+(line[one]-'A');
    }
    return temp%k;
}


long long rec(int left,int mask)
{
    if(mask==(1<<n)-1 and left==0) return 1;
    else if(mask==(1<<n)-1) return 0;
    long long &res=dp[left][mask];
    if(res==-1)
    {
        res=0;
        for(int i=0;i<n;i++)
        {
            if(check(mask,i)==0)
            {
                res+=rec(cal(left,i),on(mask,i));
            }
        }
    }
    return res;
}


int main()
{
    int test,t;
    scanf("%d",&test);
    for(t=1;t<=test;t++)
    {
        memset(dp,-1,sizeof dp);
        scanf("%d%d",&base,&k);
        scanf("%s",line);
        n=strlen(line);
        printf("Case %d: %lld\n",t,rec(0,0));
    }
    return 0;
}
