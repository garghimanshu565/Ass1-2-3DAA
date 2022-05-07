#include <bits/stdc++.h>
using namespace std;
int binarysearch(int a[],int low,int high,int x)
{
    if(high>=low)
    {
        int mid=(low+high)/2;
        if(a[mid]==x)
        {
            return mid;
        }
        if(a[mid]<x)
        {
            return binarysearch(a,mid+1,high,x);
        }
        return binarysearch(a,low,mid-1,x);
    }
    else
    {
        return -1;
    }
}
int main()
{
    int n;
    cout<<"How many elements you want to enter"<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    // sort(arr,arr+n);
    int x=50;
    int ind = binarysearch(arr,0,n-1,x);
    cout<<"Element found at index "<<ind<<endl;
    return 0;
}