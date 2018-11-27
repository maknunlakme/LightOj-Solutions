#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#define X 11000
using namespace std;

bool arr[X];
int brr[X];
vector<int> prime;
int length;

void sieve()
{
    int i,j;
    prime.push_back(2);
    for(i=3; i<=X; i+=2)
    {
        if(arr[i]==0)
        {
            prime.push_back(i);
            for(j=i; i*j<=X; j+=2)
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
}

void factor(int n)
{
    //cerr<<"H "<<endl;
    int counter,i;
    for(i=0; prime[i]<=n && prime[i]<100; i++)
    {
        if(n%prime[i]==0)
        {
            counter=1;
            while(n%prime[i]==0)
            {
                n/=prime[i];
                counter*=prime[i];
            }
            if(brr[prime[i]]<counter)
            {
                brr[prime[i]]=counter;
            }
        }
    }
    if(n>1)
    {
        if(brr[n]<n)
        {
            brr[n]=n;
        }
    }
}

string multiply( string a, int b )
{
    // a contains the biginteger in reversed form
    int carry = 0;
    for( int i = 0; i < a.size(); i++ )
    {
        carry += (a[i] - 48) * b;
        a[i] = ( carry % 10 + 48 );
        carry /= 10;
    }
    while( carry )
    {
        a += ( carry % 10 + 48 );
        carry /= 10;
    }
    return a;
}

void solve(string line)
{
    int i,j;
    char answer[1100000];
    for(i=0; i<length; i++)
    {
        if(brr[prime[i]]!=0)
        {
            line=multiply(line,brr[prime[i]]);
        }
    }
    //cerr<<line<<endl;
    int s=line.length();
    for(i=s-1,j=0; i>=0; i--,j++)
    {
        answer[j]=line[i];
    }
    answer[j]='\0';
    printf("%s",answer);
}
int main()
{
    //freopen("tempin.txt","r",stdin);
    //freopen("tempout.txt","w",stdout);
    sieve();
    length=prime.size();
    //cerr<<length<<endl;
    int test,i,j,n,temp;
    scanf("%d",&test);
    for(i=0; i<test; i++)
    {
        scanf("%d",&n);
        memset(brr,0,sizeof brr);
        for(j=0; j<n; j++)
        {
            scanf("%d",&temp);
            factor(temp);
        }
        printf("Case %d: ",i+1);
        string line="1";
        solve(line);
        printf("\n");
    }
    return 0;
}
