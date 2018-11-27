#include<iostream>
#include<cmath>
#include<algorithm>
#define M 1000007
using namespace std;
int main()
{
    long long int test,k,c,n,sum,i,j,temp,total,a[100100];
    cin>>test;
    for(i=0; i<test; i++)
    {
        cin>>k>>c>>n>>a[0];
        sum=a[0];
        total=0;
        for(j=1; j<n; j++)
        {
            a[j]=((k*a[j-1])+c)%M;
            sum+=a[j];
        }
        sort(a,a+n);
        for(j=0; j<n-1; j++)
        {
            temp=a[j]*(n-(j+1));
            sum-=a[j];
            total+=sum-temp;
        }
        cout<<"Case "<<i+1<<": "<<total<<endl;
    }
    return 0;
}
