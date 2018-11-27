#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

char mat[15][15];
bool visited[15][15];
int dist[15][15];

int fx[]={+0,+0,+1,-1};
int fy[]={+1,-1,+0,+0};

void clearing(queue<pair<int,int> >&q)
{
    queue<pair<int,int> >temp;
    swap(q,temp);
}

int n,counter;
int bfs(int a,int b)
{
    char found='B';
    queue<pair<int,int> >q;
    q.push(make_pair(a,b));
    memset(visited,0,sizeof visited);
    memset(dist,-1,sizeof dist);
    visited[a][b]=1;
    mat[a][b]='.';
    dist[a][b]=0;
    pair<int,int> u;
    int x,y,i,counting=1;
    if(counting==counter)
    {
        return  dist[a][b];
    }
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        for(i=0;i<4;i++)
        {
            x=u.first+fx[i];
            y=u.second+fy[i];
            if(x>=0&&x<n&&y>=0&&y<n&&visited[x][y]==0&&mat[x][y]!='#')
            {
                if(mat[x][y]=='.')
                {
                    visited[x][y]=1;
                    dist[x][y]=dist[u.first][u.second]+1;
                    q.push(make_pair(x,y));
                }
                else if(mat[x][y]==found)
                {
                    clearing(q);
                    counting++;
                    found++;
                    mat[x][y]='.';
                    memset(visited,0,sizeof visited);
                    dist[x][y]=dist[u.first][u.second]+1;
                    if(counting==counter)
                    {
                        return dist[x][y];
                    }
                    q.push(make_pair(x,y));
                    break;
                }
            }
        }
    }
    return -1;
}
int main()
{
    int i,j,k,test,a,b,answer=0;
    cin>>test;
    for(k=0; k<test; k++)
    {
        cin>>n;
        counter=0;
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                cin>>mat[i][j];
                if(mat[i][j]>='A'&&mat[i][j]<='Z')
                {
                    counter++;
                }
                if(mat[i][j]=='A')
                {
                    a=i;
                    b=j;
                }
            }
        }
        answer=bfs(a,b);
        if(answer==-1)
        {
            cout<<"Case "<<k+1<<": Impossible"<<endl;
        }
        else
        {
            cout<<"Case "<<k+1<<": "<<answer<<endl;
        }

    }
    return 0;
}
