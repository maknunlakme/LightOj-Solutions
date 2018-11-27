#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main()
{
    string line;
    int test,i,j,counter,length;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d",&length);
        cin>>line;
        counter=0;
        for(j=0;j<length;j++)
        {
            if(line[j]=='.')
            {
                counter++;
                j+=2;
            }
        }
        printf("Case %d: %d\n",i+1,counter);
    }
    return 0;
}
