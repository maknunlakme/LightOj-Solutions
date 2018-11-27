#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define X 1100
#define Y 1100000
using namespace std;

int arr[X],brr[X];
vector<pair<int,int> >crr;

int main()
{
    int test,i,j,k,n,length,answer,counter;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d",&n);
        crr.clear();
        for(j=0;j<n;j++)
        {
            scanf("%d%d",&arr[j],&brr[j]);
        }
        for(j=0;j<n;j++)
        {
            for(k=j+1;k<n;k++)
            {
                crr.push_back(make_pair(arr[j]+arr[k],brr[j]+brr[k]));
            }
        }
        sort(crr.begin(),crr.end());
        length=crr.size();
        counter=0;
        answer=0;
        for(j=1;j<length;j++)
        {
            if(crr[j]==crr[j-1])
            {
                counter++;
            }
            else
            {
                answer+=(counter*(counter+1))/2;
                counter=0;
            }
        }
        printf("Case %d: %d\n",i+1,answer);
    }
    return 0;
}
