#include<iostream>
#include<climits>
using namespace std;
int main()
{
    int test,n,i,j,a,b,c,maxi,mini,total;
    string name,maxiname,mininame;
    cin>>test;
    for(i=0;i<test;i++)
    {
        cin>>n;
        maxi=0;
        mini=INT_MAX;
        for(j=0;j<n;j++)
        {
            cin>>name>>a>>b>>c;
            total=a*b*c;
            if(maxi<total)
            {
                maxi=total;
                maxiname=name;
            }
            if(mini>total)
            {
                mini=total;
                mininame=name;
            }
        }
        if(maxi==mini)
        {
            cout<<"Case "<<i+1<<": no thief"<<endl;
        }
        else
        {
            cout<<"Case "<<i+1<<": "<<maxiname<<" took chocolate from "<<mininame<<endl;
        }
    }
}
