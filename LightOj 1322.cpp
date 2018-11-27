#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#define X 10010
using namespace std;

vector<pair<int,int> >arr;
char ans[X+10][6];

int main()
{
    long long n,i,j;
    long long temp,maxi=0;
    scanf("%lld",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&temp);
        arr.push_back({temp,i});
        maxi=max(maxi,temp);
    }
    sort(arr.begin(),arr.end());
    temp=1;
    for(i=1,j=0;i<=maxi and j<n;i++)
    {
        temp=temp*i+1;
        temp%=10000;
        while(arr[j].first==i)
        {
            if(i>5) snprintf(ans[arr[j].second],5,"%04lld",temp);
            else snprintf(ans[arr[j].second],5,"%lld",temp);
            j++;
        }
    }
    for(i=0;i<n;i++)
    {
        printf("Case %lld: %s\n",i+1,ans[i]);
    }
    return 0;
}
