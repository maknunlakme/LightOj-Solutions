#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
#include<cstring>
#include<vector>
#define X 110000
using namespace std;

map<int,int>mark;
int arr[X],a[X],b[X];
vector<int>brr;


int main()
{
    //freopen("tempin.txt","r",stdin);
    //freopen("tempout.txt","w",stdout);
    int test,n,i,j,counter,maxi,length;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d",&n);
        counter=1;
        maxi=0;
        memset(arr,0,sizeof arr);
        for(j=0;j<n;j++)
        {
            scanf("%d%d",&a[j],&b[j]);
            brr.push_back(a[j]);
            brr.push_back(b[j]);
        }
        sort(brr.begin(),brr.end());
        length=brr.size();
        for(j=0;j<length;j++)
        {
            if(!mark[brr[j]])
            {
                mark[brr[j]]=counter++;
            }
        }
        for(j=0;j<n;j++)
        {
            arr[mark[a[j]]]+=1;
            arr[mark[b[j]]+1]-=1;
        }
        for(j=1;j<counter;j++)
        {
            arr[j]+=arr[j-1];
            maxi=max(maxi,arr[j]);
        }
        printf("Case %d: %d\n",i+1,maxi);
        mark.clear();
        brr.clear();
    }
    return 0;
}
