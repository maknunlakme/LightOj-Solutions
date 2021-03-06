#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define X 1500
using namespace std;

vector<int>mat[X],divs[X],prime;
int arr[X+10],cost[X+10];
void sieve()
{
    int i,j;
    arr[0]=1;
    arr[1]=1;
    for(i=2; i*i<1100; i++)
    {
        if(arr[i]==0)
        {
            prime.push_back(i);
            for(j=i; i*j<1100; j++)
            {
                arr[i*j]=1;
            }
        }
    }
    for(; i<1100; i++)
    {
        if(arr[i]==0)
        {
            prime.push_back(i);
        }
    }
}

void divisors()
{
    int i,j,length=prime.size();
    for(i=4; i<1100; i++)
    {
        for(j=0; prime[j]<i&&j<length; j++)
        {
            if(i%prime[j]==0)
            {
                divs[i].push_back(prime[j]);
            }
        }
    }
}
int make_node(int a)
{
    int i,length;
    length=divs[a].size();
    for(i=0; i<length; i++)
    {
        mat[a].push_back(a+divs[a][i]);
    }
}

int bfs(int a,int b)
{
    queue<int>q;
    bool visited[X]= {0};
    memset(cost,-1,sizeof cost);
    q.push(a);
    int i,j,u,v,length;
    visited[a]=1;
    cost[a]=0;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        make_node(u);
        //cout<<"U "<<u<<endl;
        length=mat[u].size();
        for(i=0; i<length; i++)
        {
            v=mat[u][i];
            //cout<<"V "<<v<<endl;
            if(!visited[v]&&v<=b)
            {
                visited[v]=1;
                cost[v]=cost[u]+1;
                if(v==b)
                {
                    return cost[v];
                }
                q.push(v);
                //cout<<"C v "<<cost[v]<<endl;
            }
        }
    }
    return -1;
}
int main()
{
    sieve();
    divisors();
    int a,b,i,test;
    cin>>test;
    for(i=0; i<test; i++)
    {
        cin>>a>>b;
        if(a==b)
        {
            cout<<"Case "<<i+1<<": "<<0<<endl;
        }
        else
        {
            memset(mat,0,sizeof mat);
            cout<<"Case "<<i+1<<": "<<bfs(a,b)<<endl;
        }
    }
    return 0;
}
