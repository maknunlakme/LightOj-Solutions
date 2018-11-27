#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int dp1[1010],dp2[1010],arr[1010];

int rec1(int n)
{
    if(dp1[n]!=-1)
    {
        return dp1[n];
    }
    if(n<0)
    {
        return 0;
    }
    dp1[n]=max(rec1(n-2)+arr[n],rec1(n-1));
    return dp1[n];
}

int rec2(int n)
{
    if(dp2[n]!=-1)
    {
        return dp2[n];
    }
    if(n<1)
    {
        return 0;
    }
    dp2[n]=max(rec2(n-2)+arr[n],rec2(n-1));
    return dp2[n];
}

int main()
{
    int test,i,j,n;
    cin>>test;
    for(i=0;i<test;i++)
    {
        cin>>n;
        memset(dp1,-1,sizeof dp1);
        memset(dp2,-1,sizeof dp2);
        for(j=0;j<n;j++)
        {
            cin>>arr[j];
        }
        cout<<"Case "<<i+1<<": "<<max(rec1(n-2),rec2(n-1))<<endl;
    }
    return 0;
}
