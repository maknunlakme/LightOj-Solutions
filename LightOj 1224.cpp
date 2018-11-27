#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#define X 1010000
using namespace std;

vector<string>line;
int node[X][5];
int mark[X][5];
int check[300];
int root,nnode;
int isword[X];
int answer;
void initialize()
{
    root=0;
    nnode=0;
    for(int i=0; i<4; i++)
    {
        node[root][i]=-1;
        mark[root][i]=0;
    }
}

void inserting(string S)
{
    //cerr<<"HELLO "<<endl;
    int len=S.length();
    answer=max(answer,len);
    int now=root;
    int i,j;
    for(i=0; i<len; i++)
    {
        //cerr<<"WORKING "<<i<<" "<<S[i]<<endl;
        if(node[now][check[S[i]]]==-1)
        {
            node[now][check[S[i]]]=++nnode;
            mark[now][check[S[i]]]=1;
            for(j=0; j<4; j++)
            {
                node[nnode][j]=-1;
                mark[nnode][j]=0;
            }
        }
        else
        {
            mark[now][check[S[i]]]++;
            //cerr<<S[i]<<" "<<i+1<<" "<<mark[now][check[S[i]]]<<endl;
            answer=max(answer,mark[now][check[S[i]]]*(i+1));
        }
        now=node[now][check[S[i]]];
    }
    isword[now]=1;
}

int main()
{
    int test,n,i,j,length;
    check['A']=0;
    check['C']=1;
    check['G']=2;
    check['T']=3;
    char temp[X];
    scanf("%d",&test);
    for(j=0; j<test; j++)
    {
        line.clear();
        scanf("%d",&n);
        for(i=0; i<n; i++)
        {
            scanf("%s",temp);
            line.push_back(temp);
        }
        length=line.size();
        answer=0;
        initialize();
        //cerr<<"LEN "<<length<<endl;
        for(i=length-1; i>=0; i--)
        {
            inserting(line[i]);
            //cerr<<"ANS "<<line[i]<<endl;
        }
        printf("Case %d: %d\n",j+1,answer);
    }
    return 0;
}

