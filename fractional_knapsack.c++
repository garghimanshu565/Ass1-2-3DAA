#include <bits/stdc++.h>
using namespace std;
struct item
{
    int value,weight;
    item(int v,int w)
    {
        value=v;
        weight=w;
    }
};
bool cmp(struct item a,struct item b)
{
    float r1= (float)a.value/a.weight;
    float r2= (float)b.value/b.weight;
    return r1>r2;
}
float fractionalknapsack(struct item a[],int n,int size)
{
    sort(a,a+size,cmp);
    int cw=0;
    float fp=0;
    for(int i=0;i<size;i++)
    {
        if(cw+a[i].weight<=n)
        {
            fp=fp+(float)a[i].value;
            cw=cw+a[i].weight;
        }
        else
        {
            int rem=n-cw;
            cw=cw+rem;
            fp=fp+((float)a[i].value/a[i].weight)*rem;
            break;
        }
    }
    return fp;
}
int main()
{
    int N=60;
    item arr[]={{100,10},{280,40},{120,20},{120,24}};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<fractionalknapsack(arr,N,size);
    

    return 0;
}