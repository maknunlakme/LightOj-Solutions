#include<iostream>
using namespace std;
int main()
{
    long long int fact[]={1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,6227020800,87178291200,1307674368000,20922789888000,355687428096000,6402373705728000,121645100408832000,2432902008176640000};
    int test,i,j,k;
    int index[30];
    long long int n,total;
    cin>>test;
    for(i=0;i<test;i++)
    {
        cin>>n;
        for(j=0;j<22;j++)
        {
            if(fact[j]>n)
            {
                break;
            }
        }
        total=0;
        for(j--,k=0;j>-1;j--)
        {
            if(total+fact[j]<=n)
            {
                total+=fact[j];
                index[k]=j;
                k++;
            }
        }
        if(total==n)
        {
            cout<<"Case "<<i+1<<": "<<index[--k]<<"!";
            for(k--;k>-1;k--)
            {
                cout<<"+"<<index[k]<<"!";
            }
            cout<<endl;
        }
        else
        {
            cout<<"Case "<<i+1<<": impossible"<<endl;
        }
    }
    return 0;
}
