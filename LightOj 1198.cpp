#include<iostream>
#include<cstdio>
#include<algorithm>
#define X 100
using namespace std;

int arr[X],brr[X];
int mat[X][X];


int solution(int n)
{
    int i,j,add;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(arr[i-1]>brr[j-1]) add=2;
            else if(arr[i-1]==brr[j-1]) add=1;
            else add=0;
            mat[i][j]=max(max(mat[i-1][j],mat[i-1][j]),mat[i-1][j-1]+add);
        }
    }
    return mat[n][n];
}

int main()
{
    int test,n,i,j;
    scanf("%d",& test);
    for(i=0;i<test;i++)
    {
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            scanf("%d",&arr[j]);
        }
        for(j=0;j<n;j++)
        {
            scanf("%d",&brr[j]);
        }
        sort(arr,arr+n,greater<int>());
        sort(brr,brr+n,greater<int>());
        printf("Case %d: %d\n",i+1,solution(n));
    }
    return 0;
}
