#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int test,n,temp,prev,i,j,counter;
    cin>>test;
    for(i=0;i<test;i++)
    {
        cin>>n;
        counter=0;
        prev=2;
        for(j=0;j<n;j++)
        {
            cin>>temp;
            if(temp>prev)
            {
                counter+=ceil(((temp-prev)*1.0)/5.0);
            }
            prev=temp;
        }
        cout<<"Case "<<i+1<<": "<<counter<<endl;
    }
    return 0;
}
