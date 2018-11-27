#include<iostream>
#include<cstdio>
#include<algorithm>
#define X 3000
using namespace std;

int arr[X];

int main()
{
    int test,n,triangle,low,i,j,k,temp;
    scanf("%d",&test);
    for(i=0; i<test; i++)
    {
        scanf("%d",&n);
        triangle=0;
        for(j=0; j<n; j++)
        {
            scanf("%d",&arr[j]);
        }
        sort(arr,arr+n);
        for(j=0;j<n;j++)
        {
            for(k=j+1;k<n;k++)
            {
                low=upper_bound(arr+k+1,arr+n,arr[j]+arr[k]-1)-arr;
                low--;

                if(arr[low]<arr[j]+arr[k] and arr[low]>=arr[j] and arr[low]>=arr[k] and low>k)
                {
                    //cerr<<"PP "<<arr[low]<<" "<<arr[j]<<" "<<arr[k]<<endl;
                    triangle+=low-k;
                }
                //cerr<<j<<" "<<k<<" "<<arr[j]<<" "<<arr[k]<<endl;
                //cout<<arr[j]<<" "<<arr[k]<<" "<<arr[low]<<" "<<low<<" "<<k<<" "<<triangle<<endl;
            }
        }
        printf("Case %d: %d\n",i+1,triangle);
    }
    return 0;
}
