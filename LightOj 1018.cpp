#include<iostream>
#include<cstdio>
#include<cstring>
#define on(x,y) (x|(1<<y))
#define check(x,y) (x&(1<<y))
#define X 17
using namespace std;

int a[X],b[X],dp[1<<X],co[X][X];
int n,loop;

int colinear(int i,int j,int k)
{
    if(((a[k]-a[i])*(b[i]-b[j]))==((b[k]-b[i])*(a[i]-a[j]))) return 1;
    else return 0;
}

void find_colinear()
{
    memset(co,0,sizeof co);
    int i,j,k;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(i!=j)
            {
                for(k=0; k<n; k++)
                {
                    if(colinear(i,j,k))
                    {
                        co[i][j]=on(co[i][j],k);
                    }
                }
            }
            //cerr<<"RR "<<i<<" "<<j<<" "<<co[i][j]<<endl;
        }
    }
}



int rec(int mask)
{
    //cerr<<"REC "<<mask<<endl;
    if(mask>=loop) return 0;
    if(__builtin_popcount(mask)==(n-1)) return 1;
    int &ans=dp[mask];
    int i,j,k,temp;
    if(ans==-1)
    {
        ans=2000;
        for(i=0; i<n; i++)
        {
            if(check(mask,i)==0)
            {
                for(j=0; j<n; j++)
                {
                    if(i!=j and check(mask,j)==0)
                    {
                        temp=(mask|co[i][j]);
                        ans=min(ans,rec(temp)+1);
                    }
                }
                break;
            }
        }
    }
    //cerr<<"RRRRRRRRR "<<mask<<" "<<ans<<endl;
    return ans;
}


int main()
{
    //freopen("tempin.txt","r",stdin);
    //freopen("tempout.txt","w",stdout);
    int test,t,i;
    scanf("%d",&test);
    for(t=1; t<=test; t++)
    {
        memset(dp,-1,sizeof dp);
        scanf("%d",&n);
        loop=(1<<n)-1;
        for(i=0; i<n; i++)
        {
            scanf("%d%d",&a[i],&b[i]);
        }
        find_colinear();
        printf("Case %d: %d\n",t,rec(0));
    }
    return 0;
}

