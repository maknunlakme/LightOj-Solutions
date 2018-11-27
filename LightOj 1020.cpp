#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    //freopen("tempin.txt","r",stdin);
    //freopen("tempout.txt","w",stdout);
    int test,i,n;
    string name;
    cin>>test;
    for(i=0;i<test;i++)
    {
        cin>>n>>name;
        n%=3;
        if(name=="Alice")
        {
            if(n==2||n==0)
            {
                cout<<"Case "<<i+1<<": Alice"<<endl;
            }
            else
            {
                cout<<"Case "<<i+1<<": Bob"<<endl;
            }
        }
        else if(name=="Bob")
        {
            if(n==1||n==2)
            {
                cout<<"Case "<<i+1<<": Bob"<<endl;
            }
            else
            {
                cout<<"Case "<<i+1<<": Alice"<<endl;
            }
        }
    }
    return 0;
}
