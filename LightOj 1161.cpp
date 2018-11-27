#include<iostream>
#include<cstdio>
#include<cstring>
#define X 11000
using namespace std;

long long mark[X+10],kick[X+10],sum[X+10],arr[X+10];
long long ncr[X+10];

int nc4()
{
    long long i;
    ncr[4]=1;
    for(i=5;i<X;i++)
    {
        ncr[i]=(i*(i-1)*(i-2)*(i-3))/24;
        //cerr<<"II "<<i<<" "<<ncr[i]<<endl;
    }
}


int mobius()
{
    int i,j;
    for(i=0;i<X;i++) sum[i]=1,kick[i]=1;
    for(i=0;i<X;i++) kick[i]=1;
    for(int i=2; i<X; i++)
    {
        if(mark[i]==0)
        {
            for(int j=i; j<=X; j+=i)
            {
                kick[j]*=(-1);
                sum[j]*=i;
                mark[j]=1;
            }
        }
    }
    kick[1]=0;
    for(i=0;i<X;i++)
    {
        if(sum[i]!=i)
        {
            //cerr<<"SS "<<i<<" "<<sum[i]<<endl;
            kick[i]=0;
        }
    }
}



int main()
{
    nc4();
    mobius();
    long long test,i,j,k,n,answer,temp,loop;
    scanf("%lld",&test);
    for(i=0; i<test; i++)
    {
        scanf("%lld",&n);
        memset(arr,0,sizeof arr);
        loop=0;
        answer=ncr[n];
        for(j=0; j<n; j++)
        {
            scanf("%lld",&temp);
            //cerr<<"DD "<<temp<<endl;
            for(k=1;k*k<=temp;k++)
            {
                if(temp%k==0)
                {
                    arr[k]++;
                    if(temp/k!=k)
                    {
                        arr[temp/k]++;
                    }
                }
            }
            loop=max(loop,temp);
        }
        for(j=0;j<=loop;j++)
        {
            answer+=ncr[arr[j]]*kick[j];
            //cerr<<"JJJ "<<j<<" "<<answer<<" "<<arr[j]<<" "<<kick[j]<<endl;
        }
        printf("Case %lld: %lld\n",i+1,answer);
    }
    return 0;
}
