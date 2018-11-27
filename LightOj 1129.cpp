#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#define X 101000
using namespace std;

vector<string>line;
int node[X][12];
int root,nnode;
int isword[X];

void initialize()
{
    root=0;
    nnode=0;
    for(int i=0; i<10; i++)
    {
        node[root][i]=-1;
    }
}

bool inserting(string S)
{
    //cerr<<"HELLO "<<endl;
    int len=S.length();
    int now=root;
    bool check=false;
    int i,j;
    for(i=0;i<len;i++)
    {
        //cerr<<"WORKING "<<i<<" "<<S[i]<<endl;
        if(node[now][S[i]-'0']==-1)
        {
            check=true;
            node[now][S[i]-'0']=++nnode;
            for(j=0;j<10;j++)
            {
                node[nnode][j]=-1;
            }
        }
        now=node[now][S[i]-'0'];
    }
    isword[now]=1;
    return check;
}

int main()
{
    int test,n,i,j,length;
    char temp[X];
    bool no,answer;
    scanf("%d",&test);
    for(j=0;j<test;j++)
    {
        line.clear();
        no=false;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%s",temp);
            line.push_back(temp);
        }
        sort(line.begin(),line.end());
        length=line.size();
        initialize();
        //cerr<<"LEN "<<length<<endl;
        for(i=length-1;i>=0;i--)
        {
            answer=inserting(line[i]);
            //cerr<<"ANS "<<answer<<" "<<line[i]<<endl;
            if(answer==false)
            {
                no=true;
                break;
            }
        }
        if(no==true)
        {
            printf("Case %d: NO\n",j+1);
        }
        else
        {
            printf("Case %d: YES\n",j+1);
        }
    }
    return 0;
}
