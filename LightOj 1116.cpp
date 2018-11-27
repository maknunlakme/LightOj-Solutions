#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    //freopen("tempin.txt","r",stdin);
    //freopen("tempout.txt","w",stdout);
    long long int test,n,i,a,j,counter;
    bool print;
    cin>>test;
    for(i=0;i<test;i++)
    {
        cin>>n;
        a=n;
        j=2;
        counter=0;
        print=false;
        while(counter<63)
        {
            //cout<<a<<" "<<a%j<<" "<<a/j<<" "<<j<<endl;
            if(a%j==0)
            {
                if(((a/j)%2)==1)
                {
                    print=true;
                    break;
                }
            }
            j*=2;
            counter++;
        }
        if(print==false)
        {
            cout<<"Case "<<i+1<<": Impossible"<<endl;
        }
        else
        {
            cout<<"Case "<<i+1<<": "<<a/j<<" "<<j<<endl;
        }
    }
    return 0;
}
