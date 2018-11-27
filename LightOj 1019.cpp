#include<iostream>
#include<cstdio>
#include<cstring>
#include<climits>
using namespace std;

unsigned int mat[110][110];
bool mark[110][110];
int n,m;
void floyed()
{
    int i,j,k;
    for(k=1; k<=n; k++)
    {
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                //cerr<<"UP "<<i<<" "<<j<<" "<<k<<" "<<mat[i][j]<<" "<<mat[i][k]<<" "<<mat[k][j]<<endl;
                if(mat[i][j]>(mat[i][k]+mat[k][j]))
                {
                    mat[i][j]=(mat[i][k]+mat[k][j]);
                    //cerr<<"UP "<<i<<" "<<j<<" "<<k<<" "<<mat[i][j]<<endl;
                }
            }
        }
    }
}

int main()
{
    int test,i,j,u,v,w,z;
    scanf("%d",&test);
    for(z=0; z<test; z++)
    {
        scanf("%d%d",&n,&m);
        for(i=0; i<=n; i++)
        {
            for(j=0; j<=n; j++)
            {
                mat[i][j]=INT_MAX;
                mark[i][j]=0;
            }
        }
        for(i=0; i<m; i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            if(!mark[u][v])
            {
                mat[u][v]=w;
                mat[v][u]=w;
                mark[u][v]=1;
                mark[v][u]=1;
            }
            else if(w<mat[u][v])
            {
                mat[u][v]=w;
                mat[v][u]=w;
            }
        }
        for(i=1; i<=n; i++)
        {
            mat[i][i]=0;
        }
        floyed();
        if(mat[1][n]>=INT_MAX)
        {
            printf("Case %d: Impossible\n",z+1,mat[1][n]);
        }
        else
        {
            printf("Case %d: %d\n",z+1,mat[1][n]);
        }
    }
    return 0;
}

