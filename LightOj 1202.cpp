#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int test,i,r1,r2,c1,c2,r,c;
    cin>>test;
    for(i=0;i<test;i++)
    {
        cin>>r1>>c1>>r2>>c2;
        r=abs(r1-r2);
        c=abs(c1-c2);
        if(r==c)
        {
            cout<<"Case "<<i+1<<": "<<1<<endl;
        }
        else if((r%2)==(c%2))
        {
            cout<<"Case "<<i+1<<": "<<2<<endl;
        }
        else
        {
            cout<<"Case "<<i+1<<": impossible"<<endl;
        }
    }
    return 0;
}
