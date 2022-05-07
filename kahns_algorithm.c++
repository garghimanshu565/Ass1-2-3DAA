#include <bits/stdc++.h>
using namespace std;
class graph
{
    private:
        int v;
        list <int>* adj;
    public:
        graph(int v);
        void add_edge(int u,int v);
        void topological_sort();
};
graph::graph(int v)
{
    this->v=v;
    adj = new list<int>[v];
}
void graph::add_edge(int u,int v)
{
    adj[u].push_back(v);
}
void graph::topological_sort()
{
    vector <int> in_degree(v,0);
    for(int u=0;u<v;u++)
    {
        list <int> :: iterator itr;
        for(itr=adj[u].begin();itr!=adj[u].end();itr++)
        {
            in_degree[*itr]++;
        }
    }
    queue <int> q;
    for(int i=0;i<v;i++)
    {
        if(in_degree[i]==0)
        {
            q.push(i);
        }
    }
    int count=0;
    vector <int> order;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        order.push_back(u);

        list <int> :: iterator itr;
        for(itr=adj[u].begin();itr!=adj[u].end();itr++)
        {
            in_degree[*itr]--;
            if(in_degree[*itr]==0)
            {
                q.push(*itr);
            }
        }
        count++;
    }
    if(count!=v)
    {
        cout<<"There exists a cycle"<<endl;
    }
    for(int i=0;i<order.size();i++)
    {
        cout<<order[i]<<endl;
    }
}



int main()
{
    graph g(6);
    g.add_edge(5,2);
    g.add_edge(5,0);
    g.add_edge(4,0);
    g.add_edge(4,1);
    g.add_edge(2,3);
    g.add_edge(3,1);
    cout<<"Topological Sort is "<<endl;
    g.topological_sort();
    return 0;
}