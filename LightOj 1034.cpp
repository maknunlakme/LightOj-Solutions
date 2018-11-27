#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#define X 110000
using namespace std;

vector<int>mat[X],s;
bool visit[X];
int n,m;

void dfs1(int u)
{
    int i,v,length;
    visit[u]=1;
    length=mat[u].size();
    for(i=0;i<length;i++)
    {
        v=mat[u][i];
        if(visit[v]==0) dfs1(v);
    }
    s.push_back(u);
}

void dfs2(int u)
{
    int i,v,length;
    visit[u]=1;
    length=mat[u].size();
    for(i=0;i<length;i++)
    {
        v=mat[u][i];
        if(visit[v]==0) dfs2(v);
    }
}

int kosaraju()
{
    int i,counter=0;
    memset(visit,0,sizeof visit);
    for(i=1;i<=n;i++)
    {
        if(visit[i]==0) dfs1(i);
    }
    memset(visit,0,sizeof visit);
    for(i=s.size()-1;i>=0;i--)
    {
        if(visit[s[i]]==0)
        {
            counter++;
            dfs2(s[i]);
        }
    }
    return counter;
}

int main()
{
    int test,i,j,u,v;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d%d",&n,&m);
        for(j=0;j<=n;j++) mat[j].clear();
        for(j=0;j<m;j++)
        {
            scanf("%d%d",&u,&v);
            mat[u].push_back(v);
        }
        printf("Case %d: %d\n",i+1,kosaraju());
        s.clear();
    }
    return 0;
}
