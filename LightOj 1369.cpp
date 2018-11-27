#include<bits/stdc++.h>
#define X 110000
using namespace std;

long long arr[X];

int main()
{
    //freopen("tempin.txt","r",stdin);
    //freopen("tempout.txt","w",stdout);
    long long test,n,q,i,j,check,x,y;
    long long total;
    scanf("%lld",&test);
    for(i=0;i<test;i++)
    {
        scanf("%lld%lld",&n,&q);
        total=0;
        for(j=0;j<n;j++)
        {
             scanf("%lld",&arr[j]);
             total+=((n-j-1)-j)*arr[j];
             //cerr<<j<<" "<<n-j-1<<" "<<arr[j]<<endl;
        }
        printf("Case %lld:\n",i+1);
        for(j=0;j<q;j++)
        {
            scanf("%lld",&check);
            if(check==1)
            {
                printf("%lld\n",total);
            }
            else
            {
                scanf("%lld%lld",&x,&y);
                total-=((n-x-1)-x)*arr[x];
                //cerr<<n-x-1<<" "<<x<<" "<<arr[]
                arr[x]=y;
                total+=((n-x-1)-x)*arr[x];

            }
        }
    }
    return 0;
}


