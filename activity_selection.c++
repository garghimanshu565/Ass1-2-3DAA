#include <bits/stdc++.h>
using namespace std;
void activity_selection(int s[],int f[],int n)
{
    cout<<"Following activities will be selected: "<<endl;
    cout<<"1"<<" ";
    int k=0;
    for(int i=1;i<n;i++)
    {
        if(s[i]>=f[k])
        {
            k=i;
            cout<<i+1<<" ";
        }
    }
}
int main()
{
    int s[]={1,3,0,5,8,5};
    int f[]={2,4,6,7,9,9};
    int n=sizeof(s)/sizeof(s[0]);
    activity_selection(s,f,n);
    return 0;

}