#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

char blah[30];
long long fact[25];
int arr[30];

void cal_fact()
{
    fact[0]=1;
    for(int i=1; i<23; i++)
    {
        fact[i]=fact[i-1]*i;
    }

}

int main()
{
    //freopen("tempin.txt","r",stdin);
    //freopen("tempout.txt","w",stdout);
    cal_fact();
    int test,n,t;
    long long length,i,j,ans,temp,now,prev,finally;
    bool impossible;
    string answer;
    scanf("%d",&test);
    for(t=1; t<=test; t++)
    {
        answer.clear();
        scanf("%s",blah);
        scanf("%d",&n);
        string line(blah);
        impossible=false;
        length=line.length();
        sort(line.begin(),line.end());
        memset(arr,0,sizeof arr);
        for(i=0; i<length; i++)
        {
            arr[line[i]-'a']++;
        }
        ans=fact[length];
        for(i=0; i<30; i++)
        {
            if(arr[i]>0)
            {
                temp=fact[arr[i]];
                ans/=temp;
            }
        }
        if(ans<n)
        {
            impossible=true;
        }
        else
        {
            finally=0;
            while(length)
            {
                length--;
                now=0;
                prev=-1;
                ans=0;
                while(ans+finally<n)
                {
                    if(prev==-1 or line[now]!=line[prev])
                    {
                        finally+=ans;
                        if(prev!=-1)
                        {
                            arr[line[prev]-'a']++;
                        }
                        arr[line[now]-'a']--;
                        ans=fact[length];
                        for(i=0; i<30; i++)
                        {
                            if(arr[i]>0)
                            {
                                temp=fact[arr[i]];
                                ans/=temp;
                            }
                        }
                        prev=now;
                    }
                    now++;
                }
                answer.push_back(line[prev]);
                line.erase(line.begin()+prev);
            }
        }
        if(impossible==true)
        {
            printf("Case %d: Impossible\n",t);
        }
        else
        {
            printf("Case %d: %s\n",t,answer.c_str());
        }
    }
    return 0;
}
