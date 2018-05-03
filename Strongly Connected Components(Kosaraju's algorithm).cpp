/* 
 * Program to find Strongly connected components in a Directed graph (Kosaraju's Algorithm)
 * Strongly connected components are the group of vertices in which one selects any two vertices there will always be a path between them.
 * Used  
 * Time complexity= O(|V|+|E|)   (Uses DFS twice) 
 */ 
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
vector<int> adjlist1[5],adjlist2[5];
bool visited[5];
stack<int> st;

void reset_visited()            // Resets all vertices to not visited
{
    for(int i=0;i<5;i++)
        visited[i]=false;
}
    
void reverse()                  // Transposes the graph(reverse the direction of all edges)
{
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<adjlist1[i].size();j++)
            adjlist2[adjlist1[i][j]].push_back(i);
    }
}

void dfs(int u)
{
    visited[u]=true;
    for(int i=0;i<adjlist1[u].size();i++)
        if(!visited[adjlist1[u][i]])
            dfs(adjlist1[u][i]);
    st.push(u);
}

void dfs2(int u)
{
    visited[u]=true;
    cout<<u<<" ";
    for(int i=0;i<adjlist2[u].size();i++)
    {
        if(!visited[adjlist2[u][i]])
            dfs2(adjlist2[u][i]);
    }
}

int main()
{
	reset_visited();
//    adjlist1[1].push_back(0);
//    adjlist1[0].push_back(2);
//    adjlist1[2].push_back(1);
//    adjlist1[0].push_back(3);
//    adjlist1[3].push_back(4);
    adjlist1[0].push_back(3);
    adjlist1[0].push_back(2);
    adjlist1[1].push_back(3);
    adjlist1[2].push_back(3);
    adjlist1[3].push_back(4);
    adjlist1[4].push_back(0);
    for(int i=0;i<5;i++)
    {
        if(!visited[i])
            dfs(i);
    }
    reverse();
    reset_visited();
    
    while(!st.empty())
    {
        int v=st.top();
        st.pop();
        if(!visited[v])
        {
            dfs2(v);
            cout<<endl;
        }
    }
    return 0;
}
