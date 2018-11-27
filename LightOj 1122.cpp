#include<iostream>
#include<cstdio>
#include<cmath>
#define X 15
using namespace std;

int arr[X],brr[X],dp[X][X];
bool visited[X];
int counter,n,m;
int rec(int pos,int remain)
{
    if(remain==0)
    {
        counter++;
        return 0;
    }
    else if(pos>=m)
    {
        return 0;
    }
    else
    {
        for(int i=0; i<n; i++)
        {
            if(pos-1>=0)
            {
                int temp=abs(brr[pos-1]-arr[i]);
                if(temp<=2)
                {
                    brr[pos]=arr[i];
                    rec(pos+1,remain-1);
                }
            }
            else
            {
                brr[pos]=arr[i];
                rec(pos+1,remain-1);
            }
        }
    }
}


int main()
{
    int test,i,j;
    scanf("%d",&test);
    for(i=0; i<test; i++)
    {
        scanf("%d%d",&n,&m);
        for(j=0; j<n; j++)
        {
            scanf("%d",&arr[j]);
        }
        counter=0;
        rec(0,m);
        printf("Case %d: %d\n",i+1,counter);
    }
    return 0;
}
