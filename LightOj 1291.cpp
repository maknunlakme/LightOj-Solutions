#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<cstring>
#define X 10005
using namespace std;

vector<int>mat[X];
int timee;
int d[X],low[X],parent[X],counter[X];
bool visit[X];
map<pair<int,int>,bool>mark;
map<pair<int,int>,bool>::iterator it;

void find_art_point(int u)
{
    timee++;
    low[u]=d[u]=timee;
    visit[u]=1;
    int i,v;
    for(i=0;i<mat[u].size();i++)
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
                //cerr<<"ART "<<u<<" "<<v<<endl;
                mark[make_pair(u,v)]=1;
            }
        }
    }
}

int find_union(int x)
{
    if(x==parent[x]) return x;
    else return parent[x]=find_union(parent[x]);
}


int main()
{
    int test,t,n,m,i,j,u,v,ans;
    scanf("%d",&test);
    for(t=1;t<=test;t++)
    {
        memset(mat,0,sizeof mat);
        memset(visit,0,sizeof visit);
        memset(low,0,sizeof low);
        memset(parent,-1,sizeof parent);
        memset(d,0,sizeof d);
        memset(counter,0,sizeof counter);
        mark.clear();
        timee=1;
        ans=0;
        scanf("%d%d",&n,&m);
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            mat[u].push_back(v);
            mat[v].push_back(u);
        }
        for(i=0;i<n;i++)
        {
            if(!visit[i])
            {
                find_art_point(i);
            }
        }
        for(i=0;i<=n;i++)
        {
            parent[i]=i;
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<mat[i].size();j++)
            {
                v=mat[i][j];
                if(mark[make_pair(i,v)]==0 and mark[make_pair(v,i)]==0)
                {
                    u=find_union(i);
                    v=find_union(v);
                    if(u!=v)
                    {
                        parent[u]=v;
                    }

                }
            }
        }
        for(it=mark.begin();it!=mark.end();it++)
        {
            u=it->first.first;
            v=it->first.second;
            if(mark[make_pair(u,v)]==1)
            {
                u=find_union(u);
                v=find_union(v);
                counter[u]++;
                counter[v]++;
            }
        }
        for(i=0;i<n;i++)
        {
            if(counter[i]==1)
            {
                ans++;
            }
        }
        //cerr<<"AAA "<<ans<<endl;
        printf("Case %d: %d\n",t,(ans+1)/2);
    }
    return 0;
}
