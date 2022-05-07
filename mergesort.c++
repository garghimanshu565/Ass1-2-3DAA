#include <iostream>
using namespace std;
void merge(int a[],int p,int q,int r)
{
    int n1=q-p+1;
    int n2=r-(q+1)+1;
    int L[n1];
    int k1=p;
    for(int i=0;i<n1;i++)
    {
        if(k1<=q)
        {
            L[i]=a[k1];
            k1++;
        }
    }
    int R[n2];
    int k2=q+1;
    for(int i=0;i<n2;i++)
    {
        if(k2<=r)
        {
            R[i]=a[k2];
            k2++;
        }
    }
    int i=0,j=0,k=p;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            a[k++]=L[i++];
        }
        else
        {
            a[k++]=R[j++];
        }
    }
    while(i<n1)
    {
        a[k++]=L[i++];
    }
    while(j<n2)
    {
        a[k++]=R[j++];
    }
}
void mergesort(int a[],int p,int r)
{
    if(p<r)
    {
        int q=(p+r)/2;
        mergesort(a,p,q);
        mergesort(a,q+1,r);
        merge(a,p,q,r);
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
    mergesort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;

}