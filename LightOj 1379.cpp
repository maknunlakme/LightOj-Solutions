#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<cstdio>
#include<climits>
#define X 10010
using namespace std;

vector<pair<int,int> > mat1[X],mat2[X];
vector<pair<pair<int,int> , int > > edge;
int dis1[X],dis2[X];

class node
{
public:
    int road,cost;
    node(int road,int cost)
    {
        this->road=road;
        this->cost=cost;
    }
    bool operator < (const  node& p) const
    {
        return cost < p.cost;
    }
};


int dijkstra(int s,int p,int *dis,vector<pair<int,int> > mat[])
{
    priority_queue<node>q;
    q.push(node(s,0));
    dis[s]=0;
    int length,i;
    while(!q.empty())
    {
        node u=q.top();
        q.pop();
        if(dis[u.road]>=u.cost)
        {
            length=mat[u.road].size();
            for(i=0; i<length; i++)
            {
                node v=node(mat[u.road][i].first,mat[u.road][i].second);
                //cerr<<"YO "<<v.road<<" "<<v.cost<<" "<<u.road<<" "<<u.cost<<" "<<dis[v.road]<<endl;
                if(u.cost+v.cost<dis[v.road])
                {
                    dis[v.road]=u.cost+v.cost;
                    q.push(node(v.road,u.cost+v.cost));
                    //cerr<<"BO "<<v.road<<" "<<dis[v.road]<<" "<<toll[v.road]<<endl;
                }
            }
        }
    }
}
int main()
{
    int test,x,y,z,i,j,n,m,s,t,p,maxi,a,b;
    scanf("%d",&test);
    for(i=0; i<test; i++)
    {
        scanf("%d%d%d%d%d",&n,&m,&s,&t,&p);
        for(j=0; j<=n; j++)
        {
            mat1[j].clear();
            mat2[j].clear();
        }
        memset(dis1,63,sizeof dis1);
        memset(dis2,63,sizeof dis2);
        for(j=0; j<m; j++)
        {
            scanf("%d%d%d",&x,&y,&z);
            mat1[x].push_back(make_pair(y,z));
            mat2[y].push_back(make_pair(x,z));
            edge.push_back(make_pair(make_pair(x,y),z));
        }
        maxi=-1;
        dijkstra(s,p,dis1,mat1);
        dijkstra(t,p,dis2,mat2);
        for(j=0; j<m; j++)
        {
            x=edge[j].first.first;
            y=edge[j].first.second;
            z=edge[j].second;
            //cerr<<"YP "<<x<<" "<<y<<" "<<dis1[x]<<" "<<dis2[y]<<" "<<z<<endl;
            if(dis1[x]+dis2[y]+z<=p)
            {
                maxi=max(maxi,z);
            }
        }
        printf("Case %d: %d\n",i+1,maxi);
        edge.clear();
    }
    return 0;
}
