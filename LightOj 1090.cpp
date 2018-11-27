#include<iostream>
#include<algorithm>
using namespace std;

long long div(long long n,int a)
{
    long long counter=0;
    while(n%a==0)
    {
        counter++;
        n/=a;
    }
    return counter;
}

long long factzero(long long n,int a)
{
    long long counter=0;
    long long b=a;
    while(n>=b)
    {
        counter+=n/b;
        b*=a;
    }
    return counter;
}


int main()
{
    long long test,n,r,p,q,zero,i,a,b;
    cin>>test;
    for(i=0;i<test;i++)
    {
        cin>>n>>r>>p>>q;
        a=(div(p,5)*q)+factzero(n,5)-factzero(n-r,5)-factzero(r,5);
        b=(div(p,2)*q)+factzero(n,2)-factzero(n-r,2)-factzero(r,2);
        cout<<"Case "<<i+1<<": "<<min(a,b)<<endl;
    }
    return 0;
}
