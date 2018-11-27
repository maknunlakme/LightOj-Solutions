#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define X 1100
using namespace std;

int n,m,total,counter;
vector<int>mat[X+10];
int arr[X+10];
int visited[X+10];
void bfs(int a)
{
    queue<int>q;
    q.push(a);
    int i,u,v,length;
    visited[a]=1;
    total=arr[a];
    counter=1;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        //cerr<<"U "<<u<<endl;
        length=mat[u].size();
        for(i=0;i<length;i++)
        {
            v=mat[u][i];
            if(!visited[v])
            {
                visited[v]=1;
                total+=arr[v];
                //cerr<<"Total "<<total<<" "<<arr[v]<<endl;
                counter++;
                q.push(v);
            }
        }
    }
}


int main()
{
    int test,i,j,x,y,add;
    bool no;
    cin>>test;
    for(i=0; i<test; i++)
    {
        memset(visited,0,sizeof visited);
        cin>>n>>m;
        add=0;
        no=false;
        for(j=1; j<=n; j++)
        {
            cin>>arr[j];
            add+=arr[j];
        }
        for(j=0;j<m;j++)
        {
            cin>>x>>y;
            mat[x].push_back(y);
            mat[y].push_back(x);
        }
        if((add%n)==0)
        {
            for(j=1;j<=n;j++)
            {
                if(!visited[j])
                {
                    //cerr<<"J "<<j<<endl;
                    bfs(j);
                    {
                        //cerr<<"to "<<counter<<" "<<total<<" "<<add<<endl;
                        if((counter*(add/n))!=total)
                        {
                            no=true;
                            break;
                        }
                    }
                }
            }
        }
        else
        {
            no=true;
        }
        if(no==false)
        {
            cout<<"Case "<<i+1<<": Yes"<<endl;
        }
        else
        {
            cout<<"Case "<<i+1<<": No"<<endl;
        }
        for(j=0;j<X;j++)
        {
            mat[j].clear();
        }
    }
    return 0;
}
