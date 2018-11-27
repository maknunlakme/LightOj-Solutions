#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;

int arr[2100][2100];

int sweep(int i,int m)
{
    stack<int> s;
    int j=0,t,temp,area,maxi=0;
    while(j<m)
    {
        if(s.empty() or arr[i][s.top()]<=arr[i][j]) s.push(j++);
        else
        {
            t=s.top();
            s.pop();

            if(s.empty()) temp=j;
            else temp=j-s.top()-1;

            area=arr[i][t]*temp;
            maxi=max(maxi,area);
        }
    }
    while(!s.empty())
    {
        t=s.top();
        s.pop();

        if(s.empty()) temp=j;
        else temp=j-s.top()-1;

        area=arr[i][t]*temp;
        maxi=max(maxi,area);
    }
    return maxi;
}

int main()
{
    int test,i,j,t,maxi,n,m;
    char ch,temp;
    scanf("%d",&test);
    for(t=1;t<=test;t++)
    {
        maxi=0;
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
        {
            getchar();
            for(j=0;j<m;j++)
            {
                scanf("%c",&ch);
                temp=ch-'0';
                arr[i][j]=temp^1;
                if(i!=0 and arr[i][j]==1) arr[i][j]+=arr[i-1][j];
            }
        }
        for(i=0;i<n;i++)
        {
            maxi=max(maxi,sweep(i,m));
        }
        printf("Case %d: %d\n",t,maxi);
    }
    return 0;
}
