#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<sstream>
#define X 101000
using namespace std;

int node[X][53];
int root,nnode;
int isword[X];
int check[300];
int answer;
void initialize()
{
    root=0;
    nnode=0;
    for(int i=0; i<52; i++)
    {
        node[root][i]=-1;
    }
}

void inserting(string S)
{
    //cerr<<"HELLO "<<S<<endl;
    int len=S.length();
    int now=root;
    int i,j;
    for(i=0; i<len; i++)
    {
        //cerr<<"WORKING "<<i<<" "<<S[i]<<" "<<now<<" "<<nnode<<" "<<check[S[i]]<<endl;
        if(node[now][check[S[i]]]==-1)
        {
            node[now][check[S[i]]]=++nnode;
            for(j=0; j<52; j++)
            {
                node[nnode][j]=-1;
            }
        }
        now=node[now][check[S[i]]];
    }
    isword[now]++;
    //cerr<<now<<" "<<isword[now]<<endl;
}

int searching(string S)
{
    //cerr<<"HELLO "<<S<<endl;
    int len=S.length();
    int now=root;
    int i;
    for(i=0; i<len; i++)
    {
        //cerr<<"WORKING "<<i<<" "<<S[i]<<" "<<now<<" "<<nnode<<" "<<check[S[i]]<<endl;
        if(node[now][check[S[i]]]==-1)
        {
            return 0;
        }
        now=node[now][check[S[i]]];
    }
    //cerr<<"RETURNING "<<now<<" "<<isword[now]<<endl;
    return isword[now];
}

int main()
{
    int test,n,i,j,length,answer,a;
    for(i=0; i<26; i++)
    {
        check['a'+i]=i;
    }
    for(i=0; i<26; i++)
    {
        check['A'+i]=i+26;
    }
    char temp[X],thing[X];
    string some;
    //cin>>test;
    scanf("%d",&test);
    for(j=0; j<test; j++)
    {
        initialize();
        memset(isword,0,sizeof isword);
        //cin>>n;
        scanf("%d",&n);
        for(i=0; i<n; i++)
        {
            //cin>>temp;
            scanf("%s",temp);
            some=temp;
            if(some.length()>3)
            {
                some=some.substr(1,some.length()-2);
                //cerr<<"S "<<some<<endl;
                sort(some.begin(),some.end());
                some.insert(0,1,temp[0]);
                a=strlen(temp)-1;
                some+=temp[a];
            }
            //cerr<<temp<<" "<<some<<endl;
            inserting(some);
            //line.push_back(some);
        }
        //cin>>n;
        scanf("%d",&n);
        cin.ignore(100,'\n');
        printf("Case %d:\n",j+1);
        while(n--)
        {
            scanf ("%[^\n]%*c", thing);
            answer=1;
            stringstream ss;
            //cerr<<"THING "<<thing<<endl;
            ss<<thing;
            while(ss>>temp)
            {
                some=temp;
                if(some.length()>3)
                {
                    some=some.substr(1,some.length()-2);
                    sort(some.begin(),some.end());
                    some.insert(0,1,temp[0]);
                    a=strlen(temp)-1;
                    some+=temp[a];
                }
                //cerr<<"SOME "<<some<<endl;
                answer*=searching(some);
            }
            printf("%d\n",answer);
        }

    }
    return 0;
}


