#include<iostream>
using namespace std;

int main()
{
    long long int test,n,m,i;
    cin>>test;
    for(i=0;i<test;i++)
    {
        cin>>n>>m;
        cout<<"Case "<<i+1<<": "<<(n/(2*m))*m*m<<endl;
    }
    return 0;
}
