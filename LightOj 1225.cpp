#include<iostream>
using namespace std;
int main()
{
    int test,n,i,a,b;
    cin>>test;
    for(i=0;i<test;i++)
    {
        cin>>n;
        a=n;
        b=0;
        while(a>0)
        {
            b=(b*10)+a%10;
            a/=10;
        }
        if(b==n)
        {
            cout<<"Case "<<i+1<<": Yes"<<endl;
        }
        else
        {
            cout<<"Case "<<i+1<<": No"<<endl;
        }
    }
    return 0;
}
