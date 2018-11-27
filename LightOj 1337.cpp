#include<iostream>
#include<queue>
#include<cstring>
#include<cstdio>
using namespace std;

char mat[510][510];
int visited[510][510];
int dist[510][510];
int fx[]= {+1,-1,+0,+0};
int fy[]= {+0,+0,+1,-1};
int m,n,p,test;

int bfs(int a,int b,int vis)
{
    queue<pair<int,int> >q;
    q.push(make_pair(a,b));
    visited[a][b]=vis;
    pair<int,int> u;
    int i,x,y,counter=0;
    if(mat[a][b]=='C')
    {
        counter++;
    }
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        for(i=0; i<4; i++)
        {
            x=u.first+fx[i];
            y=u.second+fy[i];
            if(x>=0&&x<m&&y>=0&&y<n&&mat[x][y]!='#'&&visited[x][y]!=vis)
            {
                visited[x][y]=vis;
                if(mat[x][y]=='C')
                {
                    counter++;
                }
                q.push(make_pair(x,y));
            }
        }
    }
    return counter;
}

void bbfs(int a,int b,int counter,int vis)
{
    queue<pair<int,int> >q;
    q.push(make_pair(a,b));
    visited[a][b]=vis;
    pair<int,int> u;
    int i,x,y;
    dist[a][b]=counter;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        for(i=0; i<4; i++)
        {
            x=u.first+fx[i];
            y=u.second+fy[i];
            if(x>=0&&x<m&&y>=0&&y<n&&mat[x][y]!='#'&&visited[x][y]!=vis)
            {
                visited[x][y]=vis;
                dist[x][y]=counter;
                q.push(make_pair(x,y));
            }
        }
    }
}


int main()
{
    int i,j,k,x,y,answer;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d%d%d",&m,&n,&p);
        memset(dist,-1,sizeof dist);
        memset(visited,-1,sizeof visited);
        getchar();
        for(j=0;j<m;j++)
        {
            for(k=0;k<n;k++)
            {
                //cin>>mat[j][k];
                scanf("%c",&mat[j][k]);
                //cout<<mat[j][k]<<endl;
            }
            getchar();
        }
        printf("Case %d:\n",i+1);
        for(j=1;j<=p;j++)
        {
            scanf("%d%d",&x,&y);
            if(dist[x-1][y-1]==-1)
            {
                answer=bfs(x-1,y-1,j);
                bbfs(x-1,y-1,answer,j+1000);
                printf("%d\n",answer);
            }
            else
            {
                printf("%d\n",dist[x-1][y-1]);
            }
        }
    }
    return 0;
}
