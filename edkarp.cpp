#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int maxFlowBFS(vector<vector<int>> &graph, int source, int sink)
{
    int n = graph.size();
    vector<vector<int>> residualGraph(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        residualGraph[i] = graph[i];

    vector<int> parent(n);
    int maxFlow = 0;

    while (true)
    {
        fill(parent.begin(), parent.end(), -1);
        queue<int> q;
        q.push(source);
        parent[source] = -1;

        while (!q.empty() && parent[sink] == -1)
        {
            int u = q.front();
            q.pop();

            for (int v = 0; v < n; v++)
            {
                if (parent[v] == -1 && residualGraph[u][v] > 0)
                {
                    q.push(v);
                    parent[v] = u;
                }
            }
        }

        if (parent[sink] == -1)
            break;

        int pathFlow = INT_MAX;
        
        for (int v = sink; v != source; v = parent[v])
        {
            int u = parent[v];
            pathFlow = min(pathFlow, residualGraph[u][v]);
        }

        for (int v = sink; v != source; v = parent[v])
        {
            int u = parent[v];
            residualGraph[u][v] -= pathFlow;
            residualGraph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    int s, t;
    cin >> s >> t;

    int maxFlow = maxFlowBFS(graph, s, t);
    cout << maxFlow << endl;

    return 0;
}
