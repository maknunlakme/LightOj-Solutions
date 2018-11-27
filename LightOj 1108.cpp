#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define X 1100
using namespace std;

int dis[X+10];
int visit[X+10];

class node
{
public:
    int u,v,w;

    node(int u,int v,int w)
    {
        this->u=u;
        this->v=v;
        this->w=w;
    }
};

vector<node>mat;
vector<int>graph[X],answer;

int dfs(int u)
{
    visit[u]=1;
    answer.push_back(u);
    int i,length,v;
    length=graph[u].size();
    for(i=0; i<length; i++)
    {
        v=graph[u][i];
        if(!visit[v])
        {
            dfs(v);
        }
    }

}

int bellman_ford(int source,int n)
{
    dis[source]=0;
    int length=mat.size();
    int i,j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<length; j++)
        {
            if(dis[mat[j].u]+mat[j].w<dis[mat[j].v])
            {
                dis[mat[j].v]=dis[mat[j].u]+mat[j].w;
                //cerr<<"U "<<mat[j].u<<" "<<mat[j].v<<" "<<dis[mat[j].v]<<endl;
            }
        }
    }
}

bool neg_cycle()
{
    int length=mat.size();
    int i,j;
    bool cycle=false;
    for(j=0; j<length; j++)
    {
        if(dis[mat[j].u]+mat[j].w<dis[mat[j].v])
        {
            dis[mat[j].v]=dis[mat[j].u]+mat[j].w;
            cycle=true;
            if(!visit[mat[j].u])
            {
                dfs(mat[j].u);
            }
            //cerr<<"U "<<mat[j].u<<" "<<mat[j].v<<" "<<dis[mat[j].v]<<endl;
        }
    }
}

int main()
{
    //freopen("tempin.txt","r",stdin);
    //freopen("tempout.txt","w",stdout);
    int test,i,j,n,m,u,v,w,length;
    scanf("%d",&test);
    for(i=0; i<test; i++)
    {
        memset(dis,63,sizeof dis);
        memset(visit,0,sizeof visit);
        answer.clear();
        mat.clear();
        scanf("%d%d",&n,&m);
        for(j=0; j<=n; j++)
        {
            graph[j].clear();
        }
        for(j=0; j<m; j++)
        {
            scanf("%d%d%d",&u,&v,&w);
            mat.push_back(node(v,u,w));
            graph[v].push_back(u);
        }
        bellman_ford(0,n);
        neg_cycle();
        length=answer.size();
        if(length==0)
        {
            printf("Case %d: impossible\n",i+1);
        }
        else
        {
            printf("Case %d:",i+1);
            sort(answer.begin(),answer.end());
            for(j=0; j<length; j++)
            {
                printf(" %d",answer[j]);
            }
            printf("\n");
        }
        mat.clear();
    }
    return 0;
}
