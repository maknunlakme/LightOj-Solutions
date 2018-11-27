#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<stack>
#define X 51000
using namespace std;

vector<int>mat[X+10];
bool visit[X+10];
int cost[X+10],arr[X+10],parent[X+10];

void bfs(int s,int t)
{
    //cerr<<"ST "<<s<<" "<<t<<endl;
    queue<int>q;
    visit[s]=1;
    cost[s]=0;
    parent[s]=-1;
    q.push(s);
    int i,length,u,v;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        length=mat[u].size();
        for(i=0; i<length; i++)
        {
            v=mat[u][i];
            //cerr<<"VVV "<<u<<" "<<v<<endl;
            if(!visit[v])
            {
                visit[v]=1;
                cost[v]=cost[u]+1;
                parent[v]=u;
                //cerr<<"UUU "<<u<<" "<<v<<" "<<cost[u]<<" "<<cost[v]<<" "<<cost[u]+1<<endl;
                if(v==t) return;
                q.push(v);
            }
        }
    }
}

int find_parent(int s,int t)
{
    stack<int>pt;
    pt.push(t);
    while(parent[t]!=s)
    {
        if(parent[t]==-1)
        {
            pt.pop();
            break;
        }
        //cerr<<"TT "<<t<<" "<<parent[t]<<endl;
        pt.push(parent[t]);
        t=parent[t];
    }
    printf("%d",s);
    while(!pt.empty())
    {
        printf(" %d",pt.top());
        pt.pop();
    }
    printf("\n");
}


int main()
{
    //freopen("tempin.txt","r",stdin);
    //freopen("tempout.txt","w",stdout);
    int test,i,j,n;
    scanf("%d",&test);
    for(i=0; i<test; i++)
    {
        scanf("%d",&n);
        memset(mat,0,sizeof mat);
        memset(visit,0,sizeof visit);
        memset(cost,0,sizeof cost);
        for(j=0; j<n; j++)
        {
            scanf("%d",&arr[j]);
            //cerr<<"KKKKKK "<<j<<" "<<arr[j]<<endl;
        }
        for(j=1; j<n; j++)
        {
            //cerr<<"J "<<j<<" "<<arr[j-1]<<" "<<arr[j]<<endl;
            mat[arr[j-1]].push_back(arr[j]);
            mat[arr[j]].push_back(arr[j-1]);
        }
        for(j=0; j<X; j++)
        {
            sort(mat[j].begin(),mat[j].end());
        }
        printf("Case %d:\n",i+1);
        bfs(arr[0],arr[n-1]);
        find_parent(arr[0],arr[n-1]);
    }
    return 0;
}
