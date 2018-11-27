#include<iostream>
#include<cstring>
#include<algorithm>
#include<climits>
#include<cmath>
using namespace std;

int dp[110][110];
int test,n,arr[110];
int rec(int b,int e)
{
    if(b>e)
    {
        return 0;
    }
    else if(b==e)
    {
        return arr[b];
    }
    else if(dp[b][e]==-1)
    {
        int i,a=0,maxi=INT_MAX*(-1);
        for(i=b; i<=e; i++)
        {
            a+=arr[i];
            //cout<<"A "<<i<<" "<<e<<" "<<a<<endl;
            maxi=max(a-rec(i+1,e),maxi);
        }
        a=0;
        //maxi=INT_MAX*(-1);
        for(i=e; i>=b; i--)
        {
            a+=arr[i];
            //cout<<"A "<<i<<" "<<b<<" "<<a<<endl;
            maxi=max(a-rec(b,i-1),maxi);
        }
        dp[b][e]=maxi;
    }
    return dp[b][e];
}




int main()
{
    int i,j;
    cin>>test;
    for(i=0; i<test; i++)
    {
        cin>>n;
        memset(dp,-1,sizeof dp);
        for(j=0; j<n; j++)
        {
            cin>>arr[j];
        }
        cout<<"Case "<<i+1<<": "<<rec(0,n-1)<<endl;
    }
    return 0;
}
