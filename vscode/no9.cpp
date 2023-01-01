// represent a graph of city using adjacency list nodes shoud represent various landmarks and links should represent the distance between them use dijkstras algorithm cpp

#include <bits/stdc++.h>
using namespace std;
const int N = 6;

vector<pair<int, int>> adj[N];
void add_edge(int u, int v, int w)
{
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}
void dijkstra(int source, vector<int> &dist)
{
    dist.assign(N, INT_MAX);

    dist[source] = 0;
    set<pair<int, int>> pq;
    pq.insert({0, source});
    while (!pq.empty())
    {
        int u = pq.begin()->second;
        pq.erase(pq.begin());
        for (auto [v, w] : adj[u])
        {
            if (dist[v] > dist[u] + w)
            {
                pq.erase({dist[v], v});
                dist[v] = dist[u] + w;
                pq.insert({dist[v], v});
            }
        }
    }
}

int main()
{
    add_edge(0, 1, 10);
    add_edge(0, 2, 5);
    add_edge(1, 2, 2);
    add_edge(1, 3, 1);
    add_edge(2, 3, 3);
    add_edge(3, 4, 4);
    add_edge(4, 5, 6);

    vector<int> dist;
    dijkstra(0, dist);

    for (int i = 0; i < N; i++)
    {
        cout << "Distance from city 0 to city " << i << ": " << dist[i] << endl;
    }
    return 0;
}
