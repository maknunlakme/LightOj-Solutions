#include<iostream>
#include<climits>
#include<cstdio>
#define X 2000000
using namespace std;

int tree[X][3];
int root,node;

void initialize()
{
    root=0;
    node=0;
    tree[root][0]=-1;
    tree[root][1]=-1;
}

void inserting(int mask)
{
    int next,now,i;
    now=root;
    for(i=31; i>=0; i--)
    {
        next = (mask >> i) & 1;
        if(tree[now][next]==-1)
        {
            tree[now][next]=++node;
            tree[node][0]=-1;
            tree[node][1]=-1;
        }
        now=tree[now][next];
    }
}

int minimum(int mask)
{
    int next,answer=0,now,i;
    now=root;
    for(i=31; i>=0; i--)
    {
        next = (mask >> i) & 1;
        if(tree[now][next]!=-1)
        {
            answer <<= 1;
            now=tree[now][next];
        }
        else
        {
            answer <<= 1;
            answer++;
            now=tree[now][next ^ 1];
        }
    }
    return answer;
}

int maximum(int mask)
{
    int next,answer=0,now,i;
    now=root;
    for(i=31; i>=0; i--)
    {
        next = ((mask >> i) & 1) ^ 1;
        if(tree[now][next]!=-1)
        {
            answer <<= 1;
            answer++;
            now=tree[now][next];
        }
        else
        {
            answer <<= 1;
            now=tree[now][next ^ 1];
        }
    }
    return answer;
}

int main()
{
    int test,n,mini,maxi,i,j,temp,now;
    scanf("%d",&test);
    for(i=0; i<test; i++)
    {
        scanf("%d",&n);
        initialize();
        inserting(0);
        //scanf("%d",&temp);
        mini=INT_MAX;
        maxi=0;
        now=0;
        //inserting(temp);
        for(j=0; j<n; j++)
        {
            scanf("%d",&temp);
            now ^= temp;
            //inserting(temp);
            mini=min(mini,minimum(now));
            maxi=max(maxi,maximum(now));
            inserting(now);
        }
        printf("Case %d: %d %d\n",i+1,maxi,mini);
    }
    return 0;
}
