#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<cstring>
#define X 10005
using namespace std;

vector<int>mat[X];

bool visit[X];
int d[X],low[X],parent[X],color[X];
int timee,counter;
bool cycle;
map<pair<int,int>,bool>mark;

void find_art_point(int u)
{
    timee++;
    d[u]=low[u]=timee;
    visit[u]=1;
    int i,v;
    for(i=0; i<mat[u].size(); i++)
    {
        v=mat[u][i];
        if(v==parent[u])
        {
            continue;
        }
        else if(visit[v])
        {
            low[u]=min(low[u],d[v]);
        }
        else if(!visit[v])
        {
            parent[v]=u;
            find_art_point(v);
            low[u]=min(low[u],low[v]);
            if(d[u]<low[v])
            {
                mark[make_pair(u,v)]=1;
                mark[make_pair(v,u)]=1;
                //cerr<<"AAA " <<u<<" "<<v<<endl;
            }
        }
    }

}

void dfs(int from, int u, int c)
{
    //cerr<<"DDD "<<from<<" "<<u<<" "<<c<<endl;
    int i,v;
    counter++;
    visit[u]=1;
    color[u]=c;
    for(i=0; i<mat[u].size(); i++)
    {
        v=mat[u][i];
        if(mark[make_pair(u,v)]==0)
        {
            if(!visit[v])
            {
                dfs(u,v,c^1);
            }
            else if(visit[v] and v!=from)
            {
                if(color[u]==color[v])
                {
                    cycle=true;
                }
            }
        }
    }
}

int main()
{
    int test,t,i,j,n,m,u,v,ans;
    scanf("%d",&test);
    for(t=1; t<=test; t++)
    {
        memset(mat,0,sizeof mat);
        memset(d,0,sizeof d);
        memset(low,0,sizeof low);
        memset(parent,-1,sizeof parent);
        memset(visit,0,sizeof visit);
        mark.clear();
        timee=0;
        ans=0;
        scanf("%d%d",&n,&m);
        for(i=0; i<m; i++)
        {
            scanf("%d%d",&u,&v);
            mat[u].push_back(v);
            mat[v].push_back(u);
        }
        for(i=0; i<n; i++)
        {
            if(!visit[i])
            {
                find_art_point(i);
            }
        }
        memset(visit,0,sizeof visit);
        memset(color,-1,sizeof color);
        for(i=0; i<n; i++)
        {
            if(!visit[i])
            {
                counter=0;
                cycle=false;
                dfs(-1,i,0);
                if(cycle==true)
                {
                    ans+=counter;
                }
            }
        }
        printf("Case %d: %d\n",t,ans);
    }
    return 0;
}
