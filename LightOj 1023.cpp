#include<iostream>
#include<cstdio>
using namespace std;

int n,k,counter;
char crr[40];
int used[40];
void rec(int pos)
{
    //cerr<<pos<<" "<<crr<<endl;
    if(counter==k)
    {
        return;
    }
    else if(pos==n)
    {
        crr[pos]='\0';
        printf("%s\n",crr);
        counter++;
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(used[i]==0)
        {
            crr[pos]='A'+i;
            used[i]=1;
            rec(pos+1);
            used[i]=0;
        }
    }
}


int main()
{
    //freopen("tempin.txt","r",stdin);
    //freopen("tempout.txt","w",stdout);
    int test,i;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d%d",&n,&k);
        counter=0;
        printf("Case %d:\n",i+1);
        rec(0);
    }
    return 0;
}
