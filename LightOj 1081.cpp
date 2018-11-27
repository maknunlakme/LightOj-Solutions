#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#define X 502
using namespace std;

int mat[10][502][502],arr[502][502];
int n;

void sparse()
{
    int i,j,k;
    for(k=0; (1<<k)<=n; k++)
    {
        for(i=0; i+(1<<k)-1<n; i++)
        {
            for(j=0; j+(1<<k)-1<n; j++)
            {
                if(k==0) mat[k][i][j]=arr[i][j];
                else
                {
                    int x=max(mat[k-1][i][j],mat[k-1][i][j+(1<<(k-1))]);
                    int y=max(mat[k-1][i+(1<<(k-1))][j],mat[k-1][i+(1<<(k-1))][j+(1<<(k-1))]);
                    mat[k][i][j]=max(x,y);
                }
            }
        }
    }
}



int rmq(int a,int b,int c)
{
    int k=log2(c);
    //cerr<<"QQQQQQQQQQQQQQQQQQQQ "<<mat[a][k][b][k]<<" "<<mat[a+c-(1<<k)+1][k][b+c-(1<<k)+1][k]<<endl;
    int x=max(mat[k][a][b],mat[k][a+c-(1<<k)][b]);
    int y=max(mat[k][a][b+c-(1<<k)],mat[k][a+c-(1<<k)][b+c-(1<<k)]);
    return max(x,y);
}

int main()
{
    //freopen("tempin.txt","r",stdin);
    //freopen("tempout.txt","w",stdout);
    int test,i,j,k,q,a,b,c;
    scanf("%d",&test);
    for(i=0; i<test; i++)
    {
        scanf("%d%d",&n,&q);
        memset(mat,0,sizeof mat);
        memset(arr,0,sizeof arr);
        for(j=1; j<=n; j++)
        {
            for(k=1; k<=n; k++)
            {
                scanf("%d",&arr[j][k]);
            }
        }
        n++;
        sparse();
        printf("Case %d:\n",i+1);
        for(j=0; j<q; j++)
        {
            scanf("%d%d%d",&a,&b,&c);
            printf("%d\n",rmq(a,b,c));
        }
    }
    return 0;
}

