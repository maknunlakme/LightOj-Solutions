#include<iostream>
#include<cstdio>
using namespace std;

int rec(int n)
{
    //cerr<<"RR "<<n<<endl;
    if(n==0) return 0;
    if(n%2) return rec(n/2);
    else return n/2;
}


int main()
{
    int test,i,j,n,temp,total;
    scanf("%d",&test);
    for(i=0; i<test; i++)
    {
        int n;
        scanf("%d",&n);
        total=0;
        for(j=0; j<n; j++)
        {
            scanf("%d",&temp);
            total^=rec(temp);
        }
        if(total) printf("Case %d: Alice\n",i+1);
        else printf("Case %d: Bob\n",i+1);
    }
    return 0;
}
