#include <iostream>
#include <queue>
#include <vector>
#include<cstdio>
#include<cstring>
#include <climits>
#define X 30010
using namespace std;

vector<pair<int,int> > mat[X];
int dis[X];
bool vis[X]= {0};
int maxi,maxinode;

void Dijkstra(int source)
{
    for(int i=0; i<X; i++)
    {
        dis[i]=-1;
    }
    memset(vis,0,sizeof vis);
    priority_queue<pair<int,int> > pq;
    pair<int,int>u;
    int x,y,length;
    dis[source]=0;
    pq.push(make_pair(source,dis[source]));
    while(!pq.empty())
    {
        u=pq.top();
        pq.pop();
        x=u.first;
        y=u.second;
        if(!vis[x])
        {
            vis[x]=true;
            length=mat[x].size();
            for(int i=0; i<length; i++)
            {
                if(!vis[mat[x][i].first] && mat[x][i].second+y>dis[mat[x][i].first])
                {
                    dis[mat[x][i].first]=mat[x][i].second+y;
                    pq.push(make_pair(mat[x][i].first,dis[mat[x][i].first]));
                    if(maxi<dis[mat[x][i].first])
                    {
                        maxi=dis[mat[x][i].first];
                        maxinode=mat[x][i].first;
                    }
                }
            }
        }
    }
}

int main()
{
    //freopen("tempin.txt","r",stdin);
    //freopen("tempout.txt","w",stdout);
    int test,n,w,i,j,x,y,temp;
    cin>>test;
    for(i=0; i<test; i++)
    {
        memset(mat,0,sizeof mat);
        cin>>n;
        for(j=0; j<n-1; j++)
        {
            cin>>x>>y>>w;
            mat[x].push_back(make_pair(y,w));
            mat[y].push_back(make_pair(x,w));
        }
        maxi=0;
        maxinode=0;
        Dijkstra(0);
        //cout<<"ans "<<maxinode<<" "<<maxi<<endl;
        Dijkstra(maxinode);
        //cout<<"ans "<<maxinode<<" "<<maxi<<endl;
        cout<<"Case "<<i+1<<": "<<maxi<<endl;
    }
    return 0;
}
