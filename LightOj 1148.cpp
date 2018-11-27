#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<map>
using namespace std;
int main()
{
    //freopen("tempin.txt","r",stdin);
    //freopen("tempout.txt","w",stdout);
    int test,n,i,j,temp,total;
    cin>>test;
    for(i=0;i<test;i++)
    {
        cin>>n;
        vector<int>arr;
        map<int,int>mark;
        total=0;
        for(j=0;j<n;j++)
        {
            cin>>temp;
            arr.push_back(temp);
        }
        sort(arr.begin(),arr.end());
        for(j=0;j<n;j++)
        {
            if(!mark[arr[j]])
            {
                total+=arr[j]+1;
                mark[arr[j]]=arr[j];
            }
            else
            {
                mark[arr[j]]--;
            }
        }
        cout<<"Case "<<i+1<<": "<<total<<endl;
    }
    return 0;
}
