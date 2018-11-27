#include<iostream>
#include<cstdio>
#include<vector>
#define X 1001000
using namespace std;

int arr[X+10];
vector<int>prime;
vector<pair<long long,long long> >aa,bb,ll,cc;
int length;
bool possible;

long long big_pow(long long number,long long power)
{
    long long answer=1;
    if(power==0)
    {
        return 1;
    }
    else if(power%2==0)
    {
        answer=big_pow(number,power/2);
        answer*=answer;
    }
    else
    {
        answer=number*(big_pow(number,power-1));
    }
    return answer;
}

void sieve()
{
    int i,j;
    prime.push_back(2);
    for(i=3;i*i<=X;i+=2)
    {
        if(arr[i]==0)
        {
            prime.push_back(i);
            for(j=i;i*j<=X;j+=2)
            {
                arr[i*j]=1;
            }
        }
    }
    for(;i<=X;i+=2)
    {
        if(arr[i]==0)
        {
            prime.push_back(i);
        }
    }
}

void factor(long long n,vector<pair<long long,long long> >&temp)
{
    int i,counter;
    for(i=0;i<length&&prime[i]<=n;i++)
    {
        if(n%prime[i]==0)
        {
            counter=0;
            while(n%prime[i]==0)
            {
                n/=prime[i];
                counter++;
            }
            //cerr<<n<<" "<<prime[i]<<" "<<counter<<endl;
            temp.push_back(make_pair(prime[i],counter));
        }

    }
    if(n>1)
    {
        temp.push_back(make_pair(n,1));
    }
}

void find_c()
{
    int asize=aa.size();
    int bsize=bb.size();
    int lsize=ll.size();
    int i=0,j=0;
    while(i<asize&&j<bsize)
    {
        if(aa[i].first<bb[j].first)
        {
            cc.push_back(aa[i]);
            i++;
        }
        else if(aa[i].first>bb[j].first)
        {
            cc.push_back(bb[j]);
            j++;
        }
        else
        {
            cc.push_back(make_pair(aa[i].first,max(aa[i].second,bb[j].second)));
            i++;
            j++;
        }
    }
    while(i<asize)
    {
        cc.push_back(aa[i]);
        i++;
    }
    while(j<bsize)
    {
        cc.push_back(bb[j]);
        j++;
    }
}



void find_l(vector<pair<long long,long long> >&x,vector<pair<long long,long long> >&y)
{
    int xsize=x.size();
    int ysize=y.size();
    if(ysize<xsize)
    {
        //cerr<<"1 "<<endl;
        possible=false;
        return;
    }
    int i=0,j=0;
    while(i<xsize&&j<ysize)
    {
        //cerr<<x[i].first<<" "<<x[i].second<<" "<<y[j].first<<" "<<y[j].second<<endl;
        if(x[i].first<y[j].first)
        {
            //cerr<<"2 "<<endl;
            possible=false;
            return;
        }
        else if(x[i].first>y[j].first)
        {
            j++;
        }
        else
        {
            if(y[j].second==x[i].second)
            {
                y[j].second=0;
            }
            else if(y[j].second<x[i].second)
            {
                //cerr<<"3 "<<endl;
                possible=false;
                return;
            }
            i++;
            j++;
        }
    }
    if(i!=xsize)
    {
        possible=false;
        return;
    }
}

long long answer(vector<pair<long long,long long> >&temp)
{
    int s=temp.size();
    int i;
    long long total=1;
    for(i=0;i<s;i++)
    {
        total*=(big_pow(temp[i].first,temp[i].second));
    }
    return total;
}

int main()
{
    sieve();
    length=prime.size();
    //freopen("tempin.txt","r",stdin);
    //freopen("tempout.txt","w",stdout);
    int test,i,j;
    long long a,b,l;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        possible=true;
        scanf("%lld%lld%lld",&a,&b,&l);
        factor(a,aa);
        factor(b,bb);
        factor(l,ll);
        find_c();
        find_l(cc,ll);
        /*for(j=0;j<ll.size();j++)
        {
            cerr<<"LL "<<ll[j].first<<" "<<ll[j].second<<endl;
        }
        for(j=0;j<cc.size();j++)
        {
            cerr<<"CC "<<cc[j].first<<" "<<cc[j].second<<endl;
        }*/
        if(possible==false)
        {
            printf("Case %d: impossible\n",i+1);
        }
        else
        {
            printf("Case %d: %lld\n",i+1,answer(ll));
        }
        aa.clear();
        bb.clear();
        cc.clear();
        ll.clear();
    }
    return 0;
}
