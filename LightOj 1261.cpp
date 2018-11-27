#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;

vector<int> arr[35];
bool crr[35];

int main()
{
    int n,m,k,test,a,i,j,l,p;
    char temp;
    bool fine,yes;
    scanf("%d",&test);
    for(i=0; i<test; i++)
    {
        scanf("%d%d%d",&n,&m,&k);
        memset(crr,0,sizeof crr);
        for(j=0; j<n; j++)
        {
            arr[j].clear();
            for(l=0; l<k; l++)
            {
                cin>>temp;
                scanf("%d",&a);
                if(temp=='-')
                {
                    a*=-1;
                }
                arr[j].push_back(a);
            }
        }
        scanf("%d",&p);

        for(j=0; j<p; j++)
        {
            scanf("%d",&a);
            crr[a]=1;
        }
        yes=true;
        for(j=0; j<n; j++)
        {
            fine=false;
            for(l=0; l<k; l++)
            {
                if(arr[j][l]>0)
                {
                    if(crr[arr[j][l]]==1)
                    {
                        fine=true;
                    }
                }
                else if(arr[j][l]<0)
                {
                    arr[j][l]*=(-1);
                    if(crr[arr[j][l]]==0)
                    {
                        fine=true;
                    }
                }
            }
            if(fine==false)
            {
                yes=false;
                break;
            }
        }
        if(fine==true)
        {
            printf("Case %d: Yes\n",i+1);
        }
        else
        {
            printf("Case %d: No\n",i+1);
        }
    }
    return 0;
}
