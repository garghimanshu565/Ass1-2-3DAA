#include <bits/stdc++.h>
using namespace std;
struct job
{
    char id;
    int deadline;
    int profit;
    job(char i,int dead,int p)
    {
        id=i;
        deadline=dead;
        profit=p;
    }
};
bool cmp(job obj1,job obj2)
{
    return (obj1.profit>obj2.profit);
}
void jobseq(job a[],int n)
{
    sort(a,a+n,cmp);
    bool slot[n];
    int result[n];
    for(int i=0;i<n;i++)
    {
        slot[i]=false;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=min(n,a[i].deadline)-1;j>=0;j--)
        {
            if(slot[j]==false)
            {
                result[j]=i;
                slot[j]=true;
                break;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(slot[i])
        {
            cout<<a[result[i]].id<<endl;
        }
    }
}
int main()
{
    job arr[]={{'a',2,100},{'b',1,19},{'c',2,27},{'d',1,25},{'e',3,15}};
    int n = sizeof(arr)/sizeof(arr[0]);
    jobseq(arr,n);
    return 0;
}