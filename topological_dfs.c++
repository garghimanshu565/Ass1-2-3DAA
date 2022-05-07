#include <bits/stdc++.h>
using namespace std;
class graph
{
    private:
        int v;
        list <int>*adj;
        void topological_sort_util(int v,bool visited[],stack <int> &s);
    public:
        graph(int v);
        void topological_sort();
        void add_edge(int u,int v);

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
void graph::topological_sort_util(int v,bool visited[],stack <int> &s)
{
    visited[v]=true;
    list <int> :: iterator itr;
    for(itr=adj[v].begin();itr!=adj[v].end();itr++)
    {
        if(!visited[*itr])
        topological_sort_util(*itr,visited,s);
    }
    s.push(v);
}
void graph::topological_sort()
{   
    stack <int> s;
    bool visited[v];
    for(int i=0;i<v;i++)
    {
        visited[i]=false;
    }
    for(int i=0;i<v;i++)
    {
        if(visited[i]==false)
        {
            topological_sort_util(i,visited,s);
        }
    }
    while(s.empty()==false)
    {
        cout<<s.top()<<endl;
        s.pop();
    }

}
int main()
{
    graph g(6);
    g.add_edge(5, 2);
    g.add_edge(5, 0);
    g.add_edge(4, 0);
    g.add_edge(4, 1);
    g.add_edge(2, 3);
    g.add_edge(3, 1);
    g.topological_sort();
    return 0;
}