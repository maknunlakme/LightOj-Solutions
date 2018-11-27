#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define X 11000
using namespace std;

int arr[X],brr[1100000];

int main()
{
    int test,n,i,j;
    bool no;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d",&n);
        no=false;
        memset(brr,0,sizeof brr);
        for(j=0;j<n;j++)
        {
            scanf("%d",&arr[j]);
        }
        sort(arr,arr+n);
        for(j=0;j<n;j++)
        {
            if(arr[j]>=n)
            {
                no=true;
                break;
            }
            if(!brr[arr[j]])
            {
                brr[arr[j]]=1;
            }
            else if(!brr[n-1-arr[j]])
            {
                brr[n-1-arr[j]]=1;
            }
            else
            {
                no=true;
                break;
            }
        }
        if(no==false)
        {
            printf("Case %d: yes\n",i+1);
        }
        else
        {
            printf("Case %d: no\n",i+1);
        }
    }
    return 0;
}
