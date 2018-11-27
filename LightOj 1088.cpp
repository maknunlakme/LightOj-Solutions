#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int main()
{
    int test,n,q,qfirst,qlast,upper,lower,i,j,temp,n_arr[100100];
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        printf("Case %d:\n",i+1);
        scanf("%d%d",&n,&q);
        for(j=0;j<n;j++)
        {
            scanf("%d",&n_arr[j]);
        }
        for(j=0;j<q;j++)
        {
            scanf("%d%d",&qfirst,&qlast);
            lower=lower_bound(n_arr,n_arr+n,qfirst)-n_arr;
            upper=upper_bound(n_arr,n_arr+n,qlast)-n_arr;
            printf("%d\n",upper-lower);
        }
    }
    return 0;
}
