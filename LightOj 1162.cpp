#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<climits>
#define X 100005
using namespace std;

int level[X];
int weight[X];
int table[X][22];
int maxitable[X][22];
int minitable[X][22];
int parent[X];
int maxi,mini;
vector<pair<int,int> > mat[X];

void dfs(int from,int u,int dep,int w)
{
    parent[u]=from;
    level[u]=dep;
    weight[u]=w;
    for(int i=0; i<(int)mat[u].size(); i++)
    {
        int v=mat[u][i].first;
        if(v==from)
            continue;
        dfs(u,v,dep+1,mat[u][i].second);
    }
}

int lca_query(int p, int q)
{
    int tmp, log, i;

    if (level[p] < level[q])
        tmp = p, p = q, q = tmp;

    log=1;
    while(1)
    {
        int next=log+1;
        if((1<<next)>level[p])
            break;
        log++;

    }

    for (i = log; i >= 0; i--)
    {
        if (level[p] - (1 << i) >= level[q])
        {
            maxi=max(maxi,maxitable[p][i]);
            mini=min(mini,minitable[p][i]);
            p = table[p][i];
            //cerr<<"GG "<<p<<" "<<maxi<<" "<<mini<<endl;
        }
    }

    if (p == q)
        return p;

    for (i = log; i >= 0; i--)
    {
        //cerr<<"PPP "<<i<<" "<<p<<" "<<q<<" "<<maxi<<" "<<mini<<endl;
        //cerr<<"PAE "<<table[p][i]<<" "<<table[q][i]<<endl;
        if (table[p][i] != -1 && table[p][i] != table[q][i])
        {
            maxi=max(maxi,max(maxitable[p][i],maxitable[q][i]));
            mini=min(mini,min(minitable[p][i],minitable[q][i]));
            p = table[p][i], q = table[q][i];
            //cout<<"QQQ "<<p<<" "<<q<<" "<<maxi<<" "<<mini<<endl;
        }
    }
    maxi=max(maxi,max(maxitable[p][0],maxitable[q][0]));
    mini=min(mini,min(minitable[p][0],minitable[q][0]));
    return parent[p];
}

void lca_init(int n)
{
    memset (table,-1,sizeof table);
    int i, j;
    for (i = 1; i <= n; i++)
    {
        table[i][0] = parent[i];
        //cerr<<"AA "<<i<<" "<<parent[i]<<endl;
        maxitable[i][0] = weight[i];
        if(weight[i]!=-1)
            minitable[i][0] = weight[i];
        else minitable[i][0]=INT_MAX;
    }
    for (j = 1; (1 << j) < n; j++)
    {
        for (i = 1; i <= n; i++)
        {
            if (table[i][j - 1] != -1)
            {
                table[i][j] = table[table[i][j - 1]][j - 1];
                maxitable[i][j]=max(maxitable[i][j-1],maxitable[table[i][j-1]][j-1]);
                minitable[i][j]=min(minitable[i][j-1],minitable[table[i][j-1]][j-1]);
                //cerr<<"RR " <<i<<" "<<j<<" "<<table[i][j]<<" "<<maxitable[i][j]<<" "<<minitable[i][j]<<endl;
            }
        }
    }
}

int main()
{
    int test,t,n,m,i,u,v,w;
    scanf("%d",&test);
    for(t=1; t<=test; t++)
    {
        memset(parent,-1,sizeof parent);
        memset(weight,0,sizeof weight);
        memset(level,0,sizeof level);
        memset(mat,0,sizeof mat);
        scanf("%d",&n);
        for(i=0;i<n-1;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            mat[u].push_back(make_pair(v,w));
            mat[v].push_back(make_pair(u,w));
        }
        dfs(-1,1,0,-1);
        lca_init(n);
        scanf("%d",&m);
        printf("Case %d:\n",t);
        for(i=0;i<m;i++)
        {
            maxi=0;
            mini=INT_MAX;
            scanf("%d%d",&u,&v);
            lca_query(u,v);
            printf("%d %d\n",mini,maxi);
        }
    }
    return 0;
}
