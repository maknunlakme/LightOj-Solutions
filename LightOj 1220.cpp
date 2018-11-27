#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#define X 1000000
using namespace std;

long long power(long long a,long long b)
{
    //cerr<<"A "<<a<<" "<<b<<endl;
    if(b==0)
    {
        return 1;
    }
    long long answer;
    if(b%2==0)
    {
        answer=power(a,b/2);
        answer*=answer;
    }
    else
    {
        answer=a*power(a,b-1);
    }
    return answer;
}

int main()
{
    //freopen("tempin.txt","r",stdin);
    //freopen("tempout.txt","w",stdout);
    int test,i,j,root;
    long long answer,n,temp;
    double logn,a,b;
    bool negative;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%lld",&n);
        negative=false;
        if(n<0)
        {
            negative=true;
            n=n*(-1.0);
        }
        a=log10(n);
        root=sqrt(n);
        answer=1;
        for(j=2;j<=root;j++)
        {
            b=log10(j);
            logn=(a/b)+1e-9;
            temp=power(j,logn);
            //cerr<<a<<" "<<b<<" "<<logn<<" "<<j<<" "<<temp<<" "<<answer<<endl;
            if(n==temp)
            {
                answer=logn;
                break;
            }
        }
        if(negative==true)
        {
            while(answer%2==0)
            {
                answer/=2;
            }
        }
        printf("Case %d: %d\n",i+1,answer);
    }
    return 0;
}
