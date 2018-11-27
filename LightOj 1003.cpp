#include<iostream>
#include<cstdio>
#include<map>
#include<string>
#include<vector>
#include<cstring>
#define X 11000
using namespace std;

vector<int>mat[X];
map<string,int>mark;

int visit[X];
bool cycle;

int dfs(int u,int s)
{
    visit[u]=1;
    int i,length,v;
    length=mat[u].size();
    for(i=0;i<length;i++)
    {
        v=mat[u][i];
        if(visit[v]==0)
        {
            dfs(v,u);
        }
        else if(visit[v]==1)
        {
            cycle=true;
        }
    }
    visit[u]=2;
}

int main()
{
    //freopen("tempin.txt","r",stdin);
    //freopen("tempout.txt","w",stdout);
    int n,test,counter,i,j;
    char a[20],b[20];
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        counter=1;
        cycle=false;
        scanf("%d",&n);
        memset(visit,0,sizeof visit);
        for(j=0;j<n;j++)
        {
            scanf("%s %s",a,b);
            //cerr<<a<<" "<<b<<endl;
            if(!mark[a]) mark[a]=counter++;
            if(!mark[b]) mark[b]=counter++;
            if(mark[a]==mark[b]) cycle=true;
            mat[mark[a]].push_back(mark[b]);
        }
        for(j=1;j<=n;j++)
        {
            if(!visit[j])
            {
                dfs(j,0);
            }
        }
        if(cycle==false)
        {
            printf("Case %d: Yes\n",i+1);
        }
        else
        {
            printf("Case %d: No\n",i+1);
        }
        mark.clear();
        for(j=0;j<=counter;j++)
        {
            mat[j].clear();
        }
    }
    return 0;
}
