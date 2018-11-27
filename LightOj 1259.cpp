#include<iostream>
#include<cstdio>
#include<vector>
#define X 10000100
using namespace std;
 
vector<int>prime;
bool arr[X+10];
 
int main()
{
    int i,j,test,n,length,way;
    arr[0]=1;
    arr[1]=1;
    for(i=3; (i*i)<=X; i+=2)
    {
        if(arr[i]==0)
        {
            prime.push_back(i);
            for(j=i; (i*j)<=X; j+=2)
            {
                arr[i*j]=1;
            }
        }
    }
    for(; i<=X; i+=2)
    {
        if(arr[i]==0)
        {
            prime.push_back(i);
        }
    }
    scanf("%d",&test);
    for(i=0; i<test; i++)
    {
        scanf("%d",&n);
        if(n==4)
        {
            printf("Case %d: %d\n",i+1,1);
        }
        else
        {
            length=prime.size();
            way=0;
            for(j=0; j<length&&(prime[j]*2)<=n; j++)
            {
                //cerr<<j<<" "<<prime[j]<<" "<<n-prime[j]<<endl;
                if((arr[prime[j]]==0)&&(arr[n-prime[j]]==0))
                {
                    //cerr<<"COUNT"<<endl;
                    way++;
                }
            }
            printf("Case %d: %d\n",i+1,way);
        }
    }
    return 0;
}