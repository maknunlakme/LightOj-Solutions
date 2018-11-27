#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#define X 100005
using namespace std;

int node[X];
int level[X];
int parent[X];
int table[X][22];
vector<int>mat[X];

void dfs(int from,int u,int dep)
{
    //cerr<<"DD "<<from<<" "<<u<<" "<<dep<<endl;
    parent[u]=from;
    level[u]=dep;
    for(int i=0;i<mat[u].size();i++)
    {
        int v=mat[u][i];
        if(v==from) continue;
        dfs(u,v,dep+1);
    }
}

void lca_init(int n)
{
    memset(table,-1,sizeof table);
    int i,j;
    for(i=0;i<n;i++)
    {
        table[i][0]=parent[i];
        //cerr<<"BBB "<<i<<" "<<parent[i]<<endl;
    }
    for(j=1;(1<<j)<n;j++)
    {
        for(i=0;i<n;i++)
        {
            if(table[i][j-1]!=-1)
            {
                table[i][j]=table[table[i][j-1]][j-1];
                //cerr<<"AA "<<i<<" "<<j<<" "<<table[i][j]<<endl;
            }
        }
    }
}

int lca_query(int p,int q)
{
    int temp,log,i;

    log=1;
    while(1)
    {
        int next=log+1;
        if((1<<next)>level[p]) break;
        log++;
    }

    for(i=log;i>=0;i--)
    {
        //cerr<<"II "<<i<<" "<<p<<" "<<table[p][i]<<" "<<node[table[p][i]]<<endl;
        if(table[p][i]!=-1 and node[table[p][i]]>=q)
        {
            p=table[p][i];
        }
    }

    return p;
}


int main()
{
    #ifdef maknun
        freopen("tempin.txt","r",stdin);
        freopen("temout.txt","w",stdout);
    #endif // maknun
    int test,n,q,t,i,x,y;
    scanf("%d",&test);
    for(t=1;t<=test;t++)
    {
        memset(parent,-1,sizeof parent);
        memset(level,0,sizeof level);
        memset(mat,0,sizeof mat);
        memset(node,0,sizeof node);
        scanf("%d%d",&n,&q);
        node[0]=1;
        for(i=1;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            mat[x].push_back(i);
            node[i]=y;
        }
        printf("Case %d:\n",t);
        dfs(-1,0,1);
        lca_init(n);
        for(i=0;i<q;i++)
        {
            scanf("%d%d",&x,&y);
            printf("%d\n",lca_query(x,y));
        }
    }
    return 0;
}
