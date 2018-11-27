#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

long long arr[20];

long long enclu_exclu(long long n,long long m)
{
    long long loop=(1<<m)-1;
    //cerr<<"LL "<<loop<<endl;
    long long counter,gcd,total,sign,answer=0,i,j;
    for(i=1; i<=loop; i++)
    {
        counter=0;
        total=1;
        for(j=0; j<m; j++)
        {
            //cerr<<"PP "<<i<<" "<<j<<" "<<(i&(1<<j))<<endl;
            if((i&(1<<j))!=0)
            {
                counter++;
                gcd=__gcd(arr[j],total);
                total=(total*arr[j])/gcd;
                //cerr<<"T "<<gcd<<" "<<total<<" "<<counter<<" "<<i<<" "<<j<<" "<<(1<<j)<<endl;
            }
        }
        if(counter%2==0) sign=-1;
        else sign=1;
        answer+=sign*(n/total);
    }
    return n-answer;
}


int main()
{
    int test,i,j;
    long long n,m,answer,sign,temp;
    scanf("%d",&test);
    for(i=0; i<test; i++)
    {
        scanf("%lld%lld",&n,&m);
        sign=1;
        answer=0;
        for(j=0; j<m; j++)
        {
            scanf("%lld",&arr[j]);
        }
        printf("Case %d: %lld\n",i+1,enclu_exclu(n,m));
    }
    return 0;
}
