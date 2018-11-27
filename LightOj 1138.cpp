#include<iostream>
#define X 1000010000
using namespace std;

int countzero(int m)
{
    int i,j,counter=0;
    for(i=5;i<=m;i*=5)
    {
        counter+=m/i;
    }
    return counter;
}

int main()
{
    int test,n,i,j,k,zero;
    long long int m;
    cin>>test;
    for(i=0;i<test;i++)
    {
        cin>>n;
        j=1;
        k=X;
        while(j!=k)
        {
            m=(j+k)/2;
            zero=countzero(m);
            //cout<<m<<" "<<zero<<" "<<j<<" "<<k<<endl;
            if(zero<n)
            {
                j=m+1;
            }
            else
            {
                k=m;
            }
        }
        zero=countzero(k);
        //cout<<zero<<" K "<<k<<endl;
        if(zero==n)
        {
            cout<<"Case "<<i+1<<": "<<k<<endl;
        }
        else
        {
            cout<<"Case "<<i+1<<": impossible"<<endl;
        }
    }
    return 0;
}
