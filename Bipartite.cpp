/*
 * Check if the graph can be two colored(all adjacent vertices are of different color)
 * Uses BFS so time complexity= O(|V|+|E|)  (Uses BFS)
 */ 
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
vector<int> adjlist[9];

int main()
{
    adjlist[0].push_back(1);
    adjlist[1].push_back(0);
    adjlist[1].push_back(3);
    adjlist[1].push_back(2);
    adjlist[2].push_back(1);
    adjlist[2].push_back(3);
    adjlist[3].push_back(1);
    adjlist[3].push_back(2);
    adjlist[3].push_back(4);
    adjlist[4].push_back(3);
    adjlist[7].push_back(6);
    adjlist[6].push_back(7);
    adjlist[6].push_back(8);
    adjlist[8].push_back(6);
    
    queue<int> q;
    q.push(0);          // 0 is intial vertex
    vector<int> color(9,(1<<31));
    color[0]=0;         // color vertex 0, 0 initially
    bool isbipartite=true;
    while(!q.empty() && isbipartite)
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<adjlist[u].size();i++)
        {
            if(color[adjlist[u][i]]==(1<<31))
            {
                color[adjlist[u][i]]=1-color[u];
                q.push(adjlist[u][i]);
            }
            else if(color[adjlist[u][i]==color[u]])
            {
                isbipartite=false;
                break;
            }
        }
    }
    cout<<isbipartite<<endl; 
    return 0;
}
