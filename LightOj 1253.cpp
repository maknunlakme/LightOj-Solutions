#include<iostream>
#include<cstdio>
using namespace std;

int arr[110];

int main()
{
    int test,n,total,i,j;
    bool one;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d",&n);
        total=0;
        one=true;
        for(j=0;j<n;j++)
        {
            scanf("%d",&arr[j]);
            if(arr[j]!=1) one=false;
            total^=arr[j];
        }
        if(one==true)
        {
            if(n%2==0) printf("Case %d: Alice\n",i+1);
            else printf("Case %d: Bob\n",i+1);
        }
        else
        {
            if(total) printf("Case %d: Alice\n",i+1);
            else printf("Case %d: Bob\n",i+1);
        }
    }
    return 0;
}
