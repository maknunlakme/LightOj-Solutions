#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<cstdio>
#include<map>
#define X 100100
using namespace std;

int bfs(int node,vector<int>mat[])
{
    char visited[X];
    queue<int>q;
    int u,v,i,j,length,counter1,counter2,maxi,total=0;
    memset(visited,0,sizeof visited);
    for(j=1; j<=node; j++)
    {
        counter1=0;
        counter2=0;
        maxi=0;
        if(!visited[j])
        {
            q.push(j);
            while(!q.empty())
            {
                u=q.front();
                q.pop();
                length=mat[u].size();
                for(i=0; i<length; i++)
                {
                    v=mat[u][i];
                    if(!visited[v])
                    {
                        if(visited[u]==1)
                        {
                            visited[v]=2;
                            counter2++;
                        }
                        else
                        {
                            visited[v]=1;
                            counter1++;
                        }
                        if(maxi<counter1)
                        {
                            maxi=counter1;
                        }
                        if(maxi<counter2)
                        {
                            maxi=counter2;
                        }
                        q.push(v);
                    }
                }
            }
        }
        total+=maxi;
    }
    return total;
}

int main()
{
    //freopen("tempin.txt","r",stdin);
    //freopen("tempout.txt","w",stdout);
    int test,node,a,b,i,j,counter,answer;
    map<int,int>mark;
    cin>>test;
    for(i=0; i<test; i++)
    {
        cin>>node;
        counter=1;
        vector<int>mat[X];
        for(j=0; j<node; j++)
        {
            cin>>a>>b;
            if(!mark[a])
            {
                mark[a]=counter;
                counter++;
            }
            if(!mark[b])
            {
                mark[b]=counter;
                counter++;
            }
            mat[mark[a]].push_back(mark[b]);
            mat[mark[b]].push_back(mark[a]);
        }
        answer=bfs(counter,mat);
        cout<<"Case "<<i+1<<": "<<answer<<endl;
        mark.clear();
    }
    return 0;
}
