/* 
 * Finds Topological sort order of a given graph(MUST BE DAG)
 * Used when some vertices have dependencies on some vertices
 * Gives a proper order of sequence of tasks to be done.
 * 1) Uses DFS
 * 2) Uses Kahn's Algorithm
 * Time Complexity(of both)= O(|V|+|E|)
 */ 
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> adjlist[8];
bool visited[8];
vector<int> ts;            // Stores topological sort order

void dfs_ts(int u)         // Almost same as DFS
{
    visited[u]=true;
    for(int i=0;i<adjlist[u].size();i++)
        if(!visited[adjlist[u][i]])
            dfs_ts(adjlist[u][i]);
    ts.push_back(u);
}

void kahns()
{
    int indegree[8];
    vector<int> ans;
    queue<int> q;
    for(int i=0;i<8;i++)
        indegree[i]=0;
    for(int i=0;i<8;i++)
        for(int j=0;j<adjlist[i].size();j++)
            indegree[adjlist[i][j]]++;
    for(int i=0;i<8;i++)
        if(indegree[i]==0)
            q.push(i);
    int count=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        ans.push_back(u);
        count++;
        for(int i=0;i<adjlist[u].size();i++)
        {
            if(--indegree[adjlist[u][i]]==0)
                q.push(adjlist[u][i]);
        }
    }
    if(count!=8)
    {
        cout<<"There exists a cycle in the graph\n";
        return;
    }
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
}

int main()
{
    for(int i=0;i<8;i++)
        visited[i]=false;
    adjlist[0].push_back(1);
    adjlist[0].push_back(2);
    adjlist[1].push_back(2);
    adjlist[1].push_back(3);
    adjlist[2].push_back(3);
    adjlist[2].push_back(5);
    adjlist[3].push_back(4);
    adjlist[7].push_back(6);
    
    for(int i=0;i<8;i++)
        if(!visited[i])
            dfs_ts(i);
    
    reverse(ts.begin(),ts.end());
    for(auto t:ts)
        cout<<t<<" ";
    cout<<endl;
    kahns();
    cout<<endl;
    return 0;
}
