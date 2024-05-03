#include <iostream>
using namespace std;

int CSS (int a[],int low,int mid,int high);

int MSS(int a[],int low,int high)
{
    if(low == high)
    {
        return a[low];
    }
    int mid = (low + high)/2;
    int leftsum = MSS(a,low,mid);
    int rightsum = MSS(a,mid+1,high);
    int crosssum = CSS(a,low,mid,high);
    
    return max(leftsum,max(crosssum,rightsum));
}

int CSS(int a[],int low,int mid,int high)
{
    int lsum = INT32_MIN;
    int sum=0;
    for(int i=mid;i>=low;i--)
    {
        sum+=a[i];
        if(sum>lsum)
        {
            lsum=sum;
        }
    }
    sum=0;

    int rsum = INT32_MIN;
    for(int i=mid+1;i<high;i++)
    {
        sum+=a[i];
        if(sum>rsum)
        {
            rsum=sum;
        }
    }

    return lsum + rsum;
}

int main()
{
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    cout<<MSS(A,0,n-1);
    return 0;

}