#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<string>
#include<cstdlib>
#define X 20000
using namespace std;

vector<int>mat[X];
map<string,int>deny,mark;
map<int,string>node;
int id,visited[X],cost[X];
void bfs(string a,string b)
{
    memset(visited,0,sizeof visited);
    memset(cost,0,sizeof cost);
    queue<int>q;
    if(!mark[a])
    {
        mark[a]=id;
        node[id]=a;
        id++;
    }
    q.push(mark[a]);
    visited[mark[a]]=1;
    cost[mark[a]]=0;
    int u,v,i;
    string temp;
    while(!q.empty())
    {
        u=q.front();
        //cerr<<"U "<<u<<endl;
        q.pop();
        for(i=0;i<3;i++)
        {
            temp=node[u];
            temp[i]++;
            if(temp[i]>'z')
            {
                temp[i]='a';
            }
            if(!mark[temp])
            {
                mark[temp]=id;
                node[id]=temp;
                id++;
            }
            //cout<<"T + "<<temp<<endl;
            mat[u].push_back(mark[temp]);
        }
        for(i=0;i<3;i++)
        {
            temp=node[u];
            temp[i]--;
            if(temp[i]<'a')
            {
                temp[i]='z';
            }
            if(!mark[temp])
            {
                mark[temp]=id;
                node[id]=temp;
                id++;
            }
            //cout<<"T - "<<temp<<endl;
            mat[u].push_back(mark[temp]);
        }
        for(i=0;i<6;i++)
        {
            v=mat[u][i];
            //cout<<node[u]<<" "<<node[v]<<endl;
            //cout<<"V "<<v<<endl;
            if(!visited[v]&&!deny[node[v]])
            {
                visited[v]=1;
                cost[v]=cost[u]+1;
                //cout<<"V "<<v<<" "<<cost[v]<<endl;
                if(node[v]==b)
                {
                    return;
                }
                q.push(v);
            }
        }
    }
}

int main()
{
    int test,n,i,j,pl,ql,rl,f,g,h;
    string a,b,p,q,r;
    char c[5];
    //cerr<<"HEY"<<endl;
    cin>>test;
    for(i=0;i<test;i++)
    {
        cin>>a>>b>>n;
        //cerr<<"BLING "<<a<<" "<<b<<" "<<n<<endl;
        for(j=0;j<n;j++)
        {
            cin>>p>>q>>r;
            pl=p.length();
            ql=q.length();
            rl=r.length();
            for(f=0;f<pl;f++)
            {
                for(g=0;g<ql;g++)
                {
                    for(h=0;h<rl;h++)
                    {
                        c[0]=p[f];
                        c[1]=q[g];
                        c[2]=r[h];
                        c[3]='\0';
                        string temp(c);
                        //cout<<"temp "<<temp<<endl;
                        deny[temp]=1;
                    }
                }
            }
        }
        id=1;
        //cerr<<"deny "<<deny[a]<<" "<<a<<endl;
        if(deny[a]==1||deny[b]==1)
        {
            cout<<"Case "<<i+1<<": -1"<<endl;
        }
        else if(a==b)
        {
            cout<<"Case "<<i+1<<": 0"<<endl;
        }
        else
        {
            bfs(a,b);
            cout<<"Case "<<i+1<<": "<<cost[mark[b]]<<endl;
        }
        mark.clear();
        deny.clear();
        node.clear();
        for(j=0;j<X;j++)
        {
            mat[j].clear();
        }
    }
    return 0;
}
