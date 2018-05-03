#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<int> adjlist[4];
bool visited_dfs[4],visited_bfs[4];

void dfs(int u)
{
    visited_dfs[u]=true;
    cout<<u<<" ";
    for(int i=0;i<adjlist[u].size();i++)
    {
        if(visited_dfs[adjlist[u][i]]==false)
            dfs(adjlist[u][i]);
    }
}

void bfs(int u)
{
    queue<int> q;
    q.push(u);
    visited_bfs[u]=true;
    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        cout<<temp<<" ";
        for(int i=0;i<adjlist[temp].size();i++)
        {
            if(!visited_bfs[adjlist[temp][i]])
            {
                visited_bfs[adjlist[temp][i]]=true;
                q.push(adjlist[temp][i]);
            }
        }
    }
}

int main()
{
    for(int i=0;i<4;i++)
    {
        visited_dfs[i]=false;
        visited_bfs[i]=false;
    }
	adjlist[0].push_back(3);
	adjlist[0].push_back(2);
	adjlist[0].push_back(1);
	adjlist[1].push_back(2);
	adjlist[2].push_back(1);
	adjlist[3].push_back(0);
    
//    for(int i=0;i<4;i++)
//    {
//        for(int j=0;j<adjlist[i].size();j++)
//            cout<<adjlist[i][j]<<" ";
//        cout<<endl;
//    }
    dfs(0);
    cout<<endl;
    bfs(0);
    cout<<endl;
    return 0;
}
