#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#define X 10010
using namespace std;

vector<int>mat[X];
int parent[X],d[X],low[X];
bool visit[X],art[X];
int timee;

void find_art(int u)
{
    timee++;
    low[u]=d[u]=timee;
    visit[u]=1;
    int child=0,i,v;
    for(i=0; i<mat[u].size(); i++)
    {
        v=mat[u][i];
        child++;
        if(!visit[v])
        {
            parent[v]=u;
            find_art(v);
            low[u]=min(low[u],low[v]);
            if(d[u]<=low[v] and parent[u]!=-1)
            {
                art[u]=1;
            }
            if(child>1 and parent[u]==-1)
            {
                art[u]=1;
            }
        }
        else if(v!=parent[u])
        {
            low[u]=min(low[u],d[v]);
        }
    }
    return;
}

int main()
{
    int n,m,test,counter,i,u,v,t;
    scanf("%d",&test);
    for(t=1; t<=test; t++)
    {
        scanf("%d %d",&n,&m);
        counter=0;
        timee=0;
        memset(mat,0,sizeof mat);
        memset(art,0,sizeof art);
        memset(low,0,sizeof low);
        memset(d,0,sizeof d);
        memset(parent,-1,sizeof parent);
        memset(visit,0,sizeof visit);
        for(i=0; i<m; i++)
        {
            scanf("%d%d",&u,&v);
            mat[u].push_back(v);
            mat[v].push_back(u);
        }
        for(i=1; i<=n; i++)
        {
            if(!visit[i])
                find_art(i);
        }
        for(i=1; i<=n; i++)
        {
            if(art[i])
                counter++;
        }
        printf("Case %d: %d\n",t,counter);
    }
    return 0;
}
