#include<iostream>
#include<cstring>
#include<cstdio>
#define X 110
using namespace std;

int arr[X],n;
double dp[X][X];
bool mark[X][X];
double rec(int pos,int jump)
{
    //cerr<<"REC "<<pos<<" "<<jump<<endl;
    if(pos==n-1)
    {
        return arr[n-1];
    }
    if(mark[pos][jump]==0)
    {
        int i,div;
        dp[pos][jump]=0;
        mark[pos][jump]=1;
        for(i=1,div=0; i<=6; i++,div++)
        {
            if(pos+i<n)
            {
                dp[pos][jump]+=rec(pos+i,i);
            }
            else
            {
                break;
            }
            /*else if(pos+i==n-1)
            {
                cerr<<"TTT "<<pos<<" "<<i<<endl;
                mark[pos][jump]++;
                dp[pos][jump]+=arr[n-1];
            }*/
        }
        //cerr<<"DIV "<<div<<endl;
        dp[pos][jump]+=(arr[pos]*div);
        //cerr<<" PP "<<dp[pos][jump]<<endl;
        dp[pos][jump]/=div;
        //cerr<<"DD "<<dp[pos][jump]<<endl;
    }
    //cerr<<"PEC "<<pos<<" "<<jump<<" "<<dp[pos][jump]<<endl;
    return dp[pos][jump];
}

int main()
{
    int test,i,j;
    double temp;
    scanf("%d",&test);
    for(i=0; i<test; i++)
    {
        scanf("%d",&n);
        memset(mark,0,sizeof mark);
        for(j=0; j<n; j++)
        {
            scanf("%d",&arr[j]);
        }
        printf("Case %d: %0.9f\n",i+1,rec(0,0));

    }
    return 0;
}
