#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    //freopen("tempin.txt","r",stdin);
    //freopen("tempout.txt","w",stdout);
    int test,row,column,i,answer,temp;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d%d",&row,&column);
        if(row==1||column==1)
        {
            answer=max(row,column);
        }
        else if(row==2&&column==2)
        {
            answer=4;
        }
        else if(row==2)
        {
            answer=column/4*4;
            temp=column%4;
            if(temp==3)
            {
                temp--;
            }
            answer+=(temp*2);
        }
        else if(column==2)
        {
            answer=row/4*4;
            temp=row%4;
            if(temp==3)
            {
                temp--;
            }
            answer+=(temp*2);
        }
        else
        {
            answer=(((row+1)/2)*((column+1)/2))+((row/2)*(column/2));
        }
        printf("Case %d: %d\n",i+1,answer);
    }
    return 0;
}
