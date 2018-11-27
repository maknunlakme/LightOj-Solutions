#include<iostream>
#include<cstdio>
using namespace std;

int fibo[50];

void fibonacci()
{
    int i;
    fibo[0]=1;
    fibo[1]=1;
    for(i=2;i<=45;i++)
    {
        fibo[i]=fibo[i-1]+fibo[i-2];
        //cout<<i<<" "<<fibo[i]<<endl;
    }
}

int main()
{
    //freopen("tempin.txt","r",stdin);
    //freopen("tempout.txt","w",stdout);
    fibonacci();
    int test,n,i,j;
    cin>>test;
    for(j=0;j<test;j++)
    {
        cin>>n;
        for(i=45;i>=0;i--)
        {
            if(n>=fibo[i])
            {
                break;
            }
        }
        cout<<"Case "<<j+1<<": ";
        for(;i>0;i--)
        {
            if(n>=fibo[i])
            {
                n-=fibo[i];
                cout<<1;
            }
            else
            {
                cout<<0;
            }
        }
        cout<<endl;
    }
    return 0;
}
