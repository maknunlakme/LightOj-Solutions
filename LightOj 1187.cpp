#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int test,temp,n,i,j,ans;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d",&n);
        scanf("%d",&temp);
        ans=1;
        for(j=2;j<=n;j++)
        {
            scanf("%d",&temp);
            //cerr<<"RR "<<j<<" "<<temp<<" "<<j-temp<<" "<<ans<<endl;
            if(j-temp<=ans) ans++;
        }
        printf("Case %d: %d\n",i+1,ans);
    }
    return 0;
}
