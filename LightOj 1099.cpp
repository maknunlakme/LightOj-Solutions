#include<iostream>
#include<queue>
#include<cstdio>
#include<cstring>
#include<vector>
#include<climits>
#define X 5100
using namespace std;

unsigned int dis[X];
unsigned int dis2[X];
vector<pair<int,int> >mat[X];
int n,m;
class prioritize
{
public:
    bool operator()(pair<int,int>&p1,pair<int,int>&p2)
    {
        return p1.second>p2.second;
    }
};

void dijkstra(int source)
{
    int x,y,i,length;
    for(i=0; i<=n; i++)
    {
        dis[i]=INT_MAX;
        dis2[i]=INT_MAX;
    }
    priority_queue< pair<int,int>, vector<pair<int,int> >, prioritize>pq;
    pair<int,int>u;
    dis[source]=0;
    pq.push(make_pair(source,dis[source]));
    while(!pq.empty())
    {
        u=pq.top();
        pq.pop();
        x=u.first;
        y=u.second;
        length=mat[x].size();
        for(i=0; i<length; i++)
        {
            if(mat[x][i].second+y<dis[mat[x][i].first])
            {
                dis2[mat[x][i].first]=dis[mat[x][i].first];
                dis[mat[x][i].first]=mat[x][i].second+y;
                pq.push(make_pair(mat[x][i].first,dis[mat[x][i].first]));
                //cout<<x<<" "<<mat[x][i].first<<" "<<dis[mat[x][i].first]<<" "<<dis2[mat[x][i].first]<<endl;
            }
            else if(mat[x][i].second+y>dis[mat[x][i].first] && mat[x][i].second+y<dis2[mat[x][i].first])
            {
                dis2[mat[x][i].first]=mat[x][i].second+y;
                pq.push(make_pair(mat[x][i].first,dis2[mat[x][i].first]));
                //cout<<x<<" "<<mat[x][i].first<<" "<<dis[mat[x][i].first]<<" "<<dis2[mat[x][i].first]<<endl;
            }
        }
    }
}

int main()
{
    int test,i,j,a,b,c;
    scanf("%d",&test);
    for(i=0; i<test; i++)
    {
        scanf("%d%d",&n,&m);
        memset(mat,0,sizeof mat);
        for(j=0; j<m; j++)
        {
            scanf("%d%d%d",&a,&b,&c);
            mat[a].push_back(make_pair(b,c));
            mat[b].push_back(make_pair(a,c));
        }
        dijkstra(1);
        printf("Case %d: %d\n",i+1,dis2[n]);
    }
    return 0;
}

