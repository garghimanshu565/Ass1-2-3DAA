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
    int eulerian();
    bool is_connected();
    void dfs(int v,bool visited[]);

};
graph::graph(int v)
{
    this->v=v;
    adj=new list<int>[v];
}
void graph::add_edge(int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void graph::dfs(int v,bool visited[])
{
    visited[v]=true;
    list <int> :: iterator itr;
    for(itr=adj[v].begin();itr!=adj[v].end();itr++)
    {
        if(!visited[*itr])
        {
            dfs(*itr,visited);
        }
    }
}
bool graph::is_connected()
{
    bool visited[v];
    for(int i=0;i<v;i++)
    {
        visited[i]=false;
    }
    int i;
    for(i=0;i<v;i++)
    {
        if(adj[i].size()!=0)
            break;
    }
    if(i==v)
    {
        return true;
    }
    dfs(i,visited);
    for(int i=0;i<v;i++)
    {
        if(visited[i]==false && adj[i].size()>0)
            return false;
    }
    return true;
}
int graph::eulerian()
{
    if(is_connected()==false)
        return 0;
    int odd=0;
    for(int i=0;i<v;i++)
    {
        if(adj[i].size() & 1)
        {
            odd++;
        }
    }
    if(odd>2)
    {
        return 0;
    }
    return (odd)? 1:2;
}
void test(graph &g)
{
    int res = g.eulerian();
    if(res==0)
    {
        cout<<"Not a eulerian"<<endl;
    }
    else if(res==1)
    {
        cout<<"Eulerian path"<<endl;
    }
    else
    {
        cout<<"Eulerian cycle"<<endl;
    }
}
int main()
{
    graph g1(5);
    g1.add_edge(1,0);
    g1.add_edge(0,2);
    g1.add_edge(2,1);
    g1.add_edge(0,3);
    g1.add_edge(3,4);
    test(g1);

    graph g2(5);
    g2.add_edge(1, 0);
    g2.add_edge(0, 2);
    g2.add_edge(2, 1);
    g2.add_edge(0, 3);
    g2.add_edge(3, 4);
    g2.add_edge(4, 0);
    test(g2);

    graph g3(5);
    g3.add_edge(1, 0);
    g3.add_edge(0, 2);
    g3.add_edge(2, 1);
    g3.add_edge(0, 3);
    g3.add_edge(3, 4);
    g3.add_edge(1, 3);
    test(g3);

    return 0;
}