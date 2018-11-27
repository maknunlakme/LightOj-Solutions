#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#define X 100000
using namespace std;

double dp[X+10];
bool mark[X+10];
vector<int>d[X+10];

int divisor(int n)
{
    int i;
    for(i=2; (i*i)<=n; i++)
    {
        if(n%i==0)
        {
            d[n].push_back(i);
            //cerr<<"P "<<n<<" "<<i<<endl;
            if((i*i)!=n)
            {
                d[n].push_back(n/i);
                //cerr<<"PP "<<n<<" "<<n/i<<endl;
            }
        }

    }
}

double rec(int n)
{
    //cerr<<"HELLO"<<" "<<dp[n]<<endl;
    if(n==1)
    {
        return 0;
    }
    if(mark[n]==0)
    {
        mark[n]=1;
        //
        //cerr<<"HI"<<endl;
        divisor(n);
        int i;
        double answer=0;
        int length=d[n].size();
        if(length==0)
        {
            dp[n]=2;
        }
        else
        {
            sort(d[n].begin(),d[n].end());
            for(i=0; i<length; i++)
            {
                //cerr<<n<<" "<<d[n][i]<<endl;
                answer+=rec(d[n][i]);
            }
            length+=2;
            //cerr<<"REE "<<n<<" "<<((answer/length)+1.0)/(1.0-(1.0/length))<<endl;
            dp[n]=((answer/length)+1.0)/(1.0-(1.0/length));
        }
    }
    return dp[n];
}


int main()
{
    int test,n,i;
    scanf("%d",&test);
    for(i=0; i<test; i++)
    {
        scanf("%d",&n);
        printf("Case %d: %0.8f\n",i+1,rec(n));
    }
    return 0;
}
