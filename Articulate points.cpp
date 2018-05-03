/*
 * Program to find Articulate points in an undirected graph using DFS
 * Articulate points are the points in the graph whose removal increases the number of 
 * connected components in the graph.
 * Used to find the most vulnerable point whose failure causes most loss in a network
 * Time complexity= O(|V|+|E|) (DFS)
 */ 
#include <iostream>
#include <vector>

using namespace std;

vector<int> adjlist[11];
vector<bool> visited(11,false);
vector<int> parent(11);
vector<bool> articulate_points(11,false);
vector<int> low(11);
vector<int> discovertime(11);
int times=0;

void addedge(int v,int w)
{
    adjlist[v].push_back(w);
    adjlist[w].push_back(v);
}

void articulatefunc(int u)
{
    visited[u]=true;
    low[u]=times;
    discovertime[u]=times++;
    int children=0;
    for(int i=0;i<adjlist[u].size();i++)
    {
        int v=adjlist[u][i];
        if(!visited[v])
        {
            children++;
            parent[v]=u;
            articulatefunc(v);
            low[u]=min(low[u],low[v]);                    // Due to back edge
            if(parent[u]==-1 && children>1)               // Root has atleast two children in DFS tree
                articulate_points[u]=true;
            if(parent[u]!=-1 && low[v]>=discovertime[u])  // child(v) of non-root(u) does not has a back edge to an ancestor of u 
                articulate_points[u]=true;
        }
        else if(v!=parent[u])
            low[u]=min(low[u],discovertime[v]);
    }
}

int main()
{
	addedge(0,2);
	addedge(3,2);
	addedge(5,2);
	addedge(1,2);
	addedge(1,4);
	addedge(4,5);
	addedge(5,6);
	addedge(4,7);
	addedge(4,8);
	addedge(8,10);
	addedge(7,9);
	addedge(9,10);
    parent[0]=-1;
    articulatefunc(0);
    for(int i=0;i<11;i++)
        if(articulate_points[i])
            cout<<i<<" ";
    cout<<endl;
    return 0;
}
