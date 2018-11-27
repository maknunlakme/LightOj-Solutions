#include<iostream>
#include<set>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    //freopen("tempin.txt","r",stdin);
    //freopen("tempout.txt","w",stdout);
    int test,i,j,n,a,b,root;
    bool print;
    cin>>test;
    for(j=0;j<test;j++)
    {
        cin>>a>>b;
        print=false;
        set<int>div;
        set<int>::iterator it;
        n=a-b;
        root=sqrt(n);
        for(i=2;i<=root;i++)
        {
            if(n%i==0)
            {
                div.insert(n/i);
                div.insert(i);
            }
        }
        div.insert(1);
        div.insert(n);
        cout<<"Case "<<j+1<<":";
        for(it=div.begin();it!=div.end();it++)
        {
            if(*it>b)
            {
                cout<<" "<<*it;
                print=true;
            }
        }
        if(print==false)
        {
            cout<<" impossible"<<endl;
        }
        else
        {
            cout<<endl;
        }
    }
    return 0;
}
