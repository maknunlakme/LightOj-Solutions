#include<iostream>
#include<cstdio>
#include<cmath>
#define X 110
using namespace std;

int arr[X],brr[X];

int main()
{
    int test,total,i,j,n,temp;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            scanf("%d",&arr[j]);
        }
        for(j=0;j<n;j++)
        {
            scanf("%d",&brr[j]);
        }
        total=0;
        for(j=0;j<n;j++)
        {
            temp=abs(arr[j]-brr[j])-1;
            total^=temp;
        }
        if(total) printf("Case %d: white wins\n",i+1);
        else printf("Case %d: black wins\n",i+1);
    }
    return 0;
}
