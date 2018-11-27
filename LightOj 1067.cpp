#include<iostream>
#define X 1000003
using namespace std;

long long int fact[X+10];
long long int bigmod(long long int a,long long int b)
{
    if(b==1)
    {
        return a;
    }
    else if(b%2==1)
    {
        return((bigmod(a,b-1)*a)%X);
    }
    else
    {
        long long int temp=bigmod(a,b/2);
        return ((temp*temp)%X);
    }
}

void factorial()
{
    int i;
    fact[0]=1;
    for(i=1;i<X;i++)
    {
        fact[i]=(fact[i-1]*i)%X;
        //cerr<<i<<" "<<fact[i]<<endl;
    }
}
int main()
{
    factorial();
    long long int test,n,k,i,answer;
    cin>>test;
    for(i=0; i<test; i++)
    {
        cin>>n>>k;
        answer=fact[n];
        answer*=(bigmod(fact[n-k],X-2)%X);
        answer%=X;
        answer*=(bigmod(fact[k],X-2)%X);
        answer%=X;
        cout<<"Case "<<i+1<<": "<<answer<<endl;
    }
    return 0;
}
