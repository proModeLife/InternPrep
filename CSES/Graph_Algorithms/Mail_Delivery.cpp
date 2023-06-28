
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

void DFS(int vertex, std::unordered_map<int, std::unordered_set<int>>& graph, std::vector<int>& eulerianCycle, int& numEdges)
{
    while (!graph[vertex].empty())
    {
        int nextVertex = *graph[vertex].begin();
        graph[vertex].erase(nextVertex);
        graph[nextVertex].erase(vertex);
        DFS(nextVertex, graph, eulerianCycle, numEdges);
        ++numEdges;
    }
    
    eulerianCycle.push_back(vertex);
}

int main()
{
    int n, m;
    std::cin >> n >> m;

    std::unordered_map<int, std::unordered_set<int>> graph;

    for (int i = 0; i < m; ++i)
    {
        int a, b;
        std::cin >> a >> b;

        graph[a].insert(b);
        graph[b].insert(a);
    }
    for(int i=0;i<n;i++)
        if(graph[i].size()&1)
        {
            std::cout<<"IMPOSSIBLE"<<std::endl;
            return 0;
        }

    std::vector<int> eulerianCycle;
    int numEdges = 0;
    DFS(1, graph, eulerianCycle, numEdges);

    if (numEdges == m)
    {
        for (int vertex : eulerianCycle)
        {
            std::cout << vertex << " ";
        }
    }
    else
    {
        std::cout << "IMPOSSIBLE";
    }

    return 0;
}

