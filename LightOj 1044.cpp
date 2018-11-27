#include<iostream>
#include<cstdio>
#include<cstring>
#define inf 10000
#define X 1100
using namespace std;

char line[X];
int dp[X];
int pal[X][X];
int length;

int is_palindrome(int start,int ends)
{
    if(start>=ends) return 1;
    if(pal[start][ends]==-1)
    {
        pal[start][ends]=0;
        pal[start][ends]=((line[start]==line[ends]) and is_palindrome(start+1,ends-1));
    }
    return pal[start][ends];
}


int rec(int start)
{
    if(start>=length) return 0;
    if(dp[start]==-1)
    {
        dp[start]=inf;
        for(int i=start; i<length; i++)
        {
            if(is_palindrome(start,i)==1)
            {
                dp[start]=min(dp[start],1+rec(i+1));
            }
        }
    }
    return dp[start];
}


int main()
{
    int test,i,j;
    scanf("%d",&test);
    for(i=0; i<test; i++)
    {
        scanf("%s",line);
        memset(dp,-1,sizeof dp);
        memset(pal,-1,sizeof pal);
        length=strlen(line);
        printf("Case %d: %d\n",i+1,rec(0));
    }
    return 0;
}
