#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#define X 100010
using namespace std;

bool dp1[X];
int dp2[X];
int coin[X];
int arr[X],brr[X];
int n,m;

int res()
{
    int counter=0,i,j;
    dp1[0]=1;
    for(i=0; i<n; i++)
    {
        memset(dp2,0,sizeof dp2);
        for(j=1; j<=m; j++)
        {
            //cerr<<i<<" "<<j<<" "<<arr[i]<<" "<<j-arr[i]<<" "<<dp1[j-arr[i]]<<" "<<dp2[j-arr[i]]<<endl;
            if(dp1[j]==0 and j-arr[i]>=0 and dp1[j-arr[i]]==1 and dp2[j-arr[i]]<brr[i])
            {
                //cerr<<"PPP"<<endl;
                dp1[j]=1;
                dp2[j]=dp2[j-arr[i]]+1;
            }
        }
    }
    for(i=1; i<=m; i++)
    {
        if(dp1[i]==1) counter++;
        //cerr<<"GFF "<<i<<" "<<dp1[i]<<endl;
    }
    return counter;
}


int main()
{
    int test,i,j;
    scanf("%d",&test);
    for(i=0; i<test; i++)
    {
        scanf("%d%d",&n,&m);
        memset(dp1,0,sizeof dp1);
        for(j=0; j<n; j++) scanf("%d",&arr[j]);
        for(j=0; j<n; j++) scanf("%d",&brr[j]);
        printf("Case %d: %d\n",i+1,res());
    }
    return 0;
}
