#include<bits/stdc++.h>>
using namespace std;
int caseno = 1;
#define nl '\n'
#define sf scanf
#define pf printf
#define pb push_back
#define pp pop_back
#define FOR(N) for(I = 1; I <=N; I++)
#define REV(N) for(I = N; I > 0; I--)
#define CLR(ar) memset(ar, 0, sizeof(ar))
#define SET(ar) memset(ar, -1, sizeof(ar))
#define PC() printf("Case %d: ", caseno++)
//#define BOOST std::ios_base::sync_with_stdio(0);

typedef long long int LL;
typedef long long l;
typedef unsigned long long ULL;
#define mod 1000
long long int big_mod(long long int base,long long int power)
{
    if(power==0)
        return 1;
    else if(power%2!=0)
    {
        long long  int p1=base%mod;
        long long int p2=(big_mod(base,power-1))%mod;
        return (p1*p2)%mod;
    }
    else
    {
        long long  int p1=(big_mod(base,power/2))%mod;
        return (p1*p1)%mod;
    }
}

int first_three(LL n, LL k)
{
    double x=k*log10(n);
    return int(pow(10,x-LL(x))*100);
}

int digits(int b)
{
    int count=0;
    while(b>0)
    {
        count++;
        b/=10;
    }
    if(count<2)
        return 2;
    else if(count<3)
        return 1;
    return 0;
}
int main()
{
    //freopen("tempin.txt","r",stdin);
    //freopen("tempout.txt","w",stdout);
    //BOOST;
    LL n,i,j,k,a,b,c,x,y,z;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        sf("%lld%lld",&x,&y);
        PC();
        a=first_three(x,y);
        b=big_mod(x,y);
        c=digits(b);
        pf("%lld ",a);
        while(c--)
            pf("0");
        pf("%lld\n",b);
    }

    return 0;
}
