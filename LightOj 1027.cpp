#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int arr[110];

int main()
{
    int test,n,counter,i,j,total,g;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d",&n);
        counter=0;
        total=0;
        for(j=0;j<n;j++)
        {
            scanf("%d",&arr[i]);
            total+=abs(arr[i]);
            if(arr[i]<0)
            {
                counter++;
            }
        }
        counter=n-counter;
        g=__gcd(total,counter);
        if(counter==0)
        {
            printf("Case %d: inf\n",i+1);
        }
        else
        {
            printf("Case %d: %d/%d\n",i+1,total/g,counter/g);
        }
    }
    return 0;
}
