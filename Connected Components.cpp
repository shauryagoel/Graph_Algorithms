/*
 * Program to find and print connected components in a graph
 * A Connected component is group of vertice(s) in which each vertex is connected to other vertex through a path
 * It can consist of a single vertex too
 */ 
#include <iostream>
#include <vector>

using namespace std;

bool visited[9];
vector <int> adjlist[9];

void dfs(int u)
{
    visited[u]=true;
    cout<<u<<" ";
    for(int i=0;i<adjlist[u].size();i++)
    {
        if(!visited[adjlist[u][i]])
            dfs(adjlist[u][i]);
    }
}

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
    for(int i=0;i<9;i++)
        visited[i]=false;
    int ccno=1;
    for(int i=0;i<9;i++)
    {
        if(!visited[i])
        {
            printf("Connected Component %d: ",ccno++);
            dfs(i);
            printf("\n");
        }
    }
    return 0;
}
