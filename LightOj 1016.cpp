#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define X 100000
using namespace std;

int y[X];

int main()
{
    int n,w,test,i,j,x,start,counter;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        counter=0;
        scanf("%d%d",&n,&w);
        for(j=0;j<n;j++)
        {
            scanf("%d%d",&x,&y[j]);
        }
        sort(y,y+n);
        start=y[0];
        for(j=1;j<n;j++)
        {
            //cerr<<start<<" "<<y[j]<<endl;
            if(y[j]-start>w)
            {
                counter++;
                start=y[j];
            }
        }
        printf("Case %d: %d\n",i+1,counter+1);
    }
    return 0;
}
