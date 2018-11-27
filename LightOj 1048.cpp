#include<iostream>
#include<cstdio>
#define X 2147483647
using namespace std;

int walk[1050];
bool check(int mile,int n,int k,int a[])
{
    int camp=0,totalk=0,i;
    for(i=0; i<=n; i++)
    {
        //cout<<"what is wrong "<<a[i]<<endl;
        if(a[i]>mile)
        {
            //cout<<"doing"<<endl;
            return false;
        }
        else
        {
            if(camp+a[i]>mile)
            {
                totalk++;
                //cout<<"pushed "<<camp<<endl;
                camp=a[i];
                //cout<<totalk<<" "<<k<<" "<<camp<<" "<<mile<<endl;
                if(totalk==k+1)
                {
                    //cout<<"for no reason"<<endl;
                    return false;
                }
            }
            else
            {
                camp+=a[i];
                //cout<<"adding "<<camp<<" "<<a[i]<<endl;
            }
        }
    }
    //cout<<"why true"<<endl;
    return true;
}

int printwalk(int mile,int n,int k,int a[])
{
    int camp=0,totalk=0,i,j,l=0,totaln=n;
    for(i=0; i<=n; i++)
    {
        if(camp+a[i]>mile&&totaln>=k)
        {
            walk[l]=camp;
            l++;
            camp=a[i];
        }
        else if(totaln>k)
        {
            camp+=a[i];
            totaln--;
        }
        else
        {
            walk[l]=camp+a[i];
            l++;
            camp=0;
        }
    }
    walk[l]=camp;
    return l;
}


int main()
{
    int test,n,k,arr[1050],mile,i,j,p,q,length;
    long long int m;
    scanf("%d",&test);
    for(i=0; i<test; i++)
    {
        scanf("%d%d",&n,&k);
        for(j=0; j<=n; j++)
        {
            scanf("%d",&arr[j]);
        }
        p=1;
        q=X;
        while(p<q)
        {
            m=(p+q)/2;
            //cout<<p<<" "<<q<<" "<<m<<endl;
            if(check(m,n,k,arr)==true)
            {
                q=m;
            }
            else
            {
                p=m+1;
            }
        }
        printf("Case %d: %d\n",i+1,q);
        length=printwalk(p,n,k,arr);
        for(j=0; j<length; j++)
        {
            printf("%d\n",walk[j]);
        }
    }
    return 0;
}
