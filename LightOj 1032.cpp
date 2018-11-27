#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;

long long dp[40][2][2][40];
int length;
string a;
string baseconvert(int from, int to, string line)
{
    int length=line.length();
    string result;
    char tempchar;
    long long int i,j,total=0,temp,rem;
    for(i=length-1,j=0; i>-1; i--,j++)
    {
        if(line[i]>='0'&&line[i]<='9')
        {
            temp=line[i]-'0';
        }
        else if(line[i]>='A'&&line[i]<='Z')
        {
            temp=line[i]-'7';
        }
        if(temp>=from)
        {
            return "blank";
        }
        total+=ceil(temp*pow(from,j));
    }
    if(total>0)
    {
        if(to<10)
        {
            while(total!=0)
            {
                rem=total%to;
                total/=to;
                tempchar=rem+'0';
                result.insert(0,1,tempchar);
            }
        }
        else
        {
            while(total!=0)
            {
                rem=total%to;
                total/=to;
                if(rem>9)
                {
                    tempchar=rem+'7';
                }
                else
                {
                    tempchar=rem+'0';
                }
                result.insert(0,1,tempchar);
            }
        }
    }
    if(result.size()==0)
    {
        result="0";
    }
    return result;
}

long long rec(int pos,bool small,int last,long long value)
{
    if(pos>=length)
    {
        return value;
    }
    if(dp[pos][small][last][value]==-1)
    {
        dp[pos][small][last][value]=0;
        int limit=1,i;
        if(small==false)
        {
            limit=a[pos]-'0';
        }
        for(i=0;i<=limit;i++)
        {
            //cerr<<pos<<" "<<i<<endl;
            dp[pos][small][last][value]+=rec(pos+1,max(small,i<a[pos]-'0'),(i==1),value+(i==1&&last==1));
        }
    }
    return dp[pos][small][last][value];
}


int main()
{
    int test,i,n;
    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        memset(dp,-1,sizeof dp);
        cin>>a;
        a=baseconvert(10,2,a);
        length=a.length();
        //cerr<<a<<endl;
        printf("Case %d: %lld\n",i+1,rec(0,0,0,0));
    }
    return 0;
}
