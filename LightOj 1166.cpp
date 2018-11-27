#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
    //freopen("tempin.txt","r",stdin);
    //freopen("tempout.txt","w",stdout);
    int test,n,i,j,arr[110],counter;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d",&n);
        counter=0;
        for(j=0;j<n;j++)
        {
            scanf("%d",&arr[j]);
        }
        j=0;
        while(j<n)
        {
            if(arr[j]==j+1)
            {
                j++;
            }
            else
            {
                //cerr<<j<<" "<<arr[j]<<" "<<arr[arr[j]-1]<<endl;
                swap(arr[j],arr[arr[j]-1]);
                counter++;
            }
        }
        printf("Case %d: %d\n",i+1,counter);
    }
    return 0;
}
