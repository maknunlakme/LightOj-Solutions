#include<iostream>
using namespace std;
int main()
{
    int test,a,b,i;
    cin>>test;
    for(i=0;i<test;i++)
    {
        cin>>a>>b;
        cout<<"Case "<<i+1<<": "<<a+b<<endl;
    }
    return 0;
}
