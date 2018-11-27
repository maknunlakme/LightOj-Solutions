#include <iostream>
#include <queue>
#include <vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define X 30010
using namespace std;

vector<pair<int,int> > mat[X];
int dis[X];
bool vis[X]= {0};
int maxi,maxinode;
int maximus[X];
void Dijkstra(int source)
{
    memset(vis,0,sizeof vis);
    memset(dis,-1,sizeof dis);
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
    int test,n,w,i,j,x,y;
    scanf("%d",&test);
    for(i=0; i<test; i++)
    {
        memset(mat,0,sizeof mat);
        memset(maximus,-1,sizeof maximus);
        scanf("%d",&n);
        for(j=0; j<n-1; j++)
        {
            scanf("%d%d%d",&x,&y,&w);
            mat[x].push_back(make_pair(y,w));
            mat[y].push_back(make_pair(x,w));
        }
        printf("Case %d:\n",i+1);
        maxi=0;
        maxinode=0;
        Dijkstra(0);
        maxi=0;
        //cout<<"max 1 "<<maxinode<<endl;
        Dijkstra(maxinode);
        //cout<<"max 2 "<<maxinode<<endl;
        copy(dis,dis+n,maximus);
        maxi=0;
        //maximus[maxinode]=maxi;
        Dijkstra(maxinode);
        //cout<<"max 3 "<<maxinode<<endl;
        for(j=0;j<n;j++)
        {
            //cout<<maximus[j]<<" "<<dis[j]<<endl;
            printf("%d\n",max(maximus[j],dis[j]));
        }
    }
    return 0;
}
