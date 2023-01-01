// represent a graph of college campususing adjacency list nodes shoud represent various departments and links should represent the distance between them use kruskals algorithm cpp

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

class Edge
{
public:
    std::string source;
    std::string destination;
    int weight;
    Edge(std::string source, std::string destination, int weight)
    {
        this->source = source;
        this->destination = destination;
        this->weight = weight;
    }
};

class Graph
{
public:
    std::unordered_map<std::string, std::vector<Edge>> adjacencyList;

    void addEdge(std::string source, std::string destination, int weight)
    {
        adjacencyList[source].push_back(Edge(source, destination, weight));
        adjacencyList[destination].push_back(Edge(destination, source, weight));
    }
};

class UnionFind
{
public:
    std::unordered_map<std::string, std::string> parent;

    std::string find(std::string element)
    {
        if (parent[element] == element)
        {
            return element;
        }
        return parent[element] = find(parent[element]);
    }

    void unionSet(std::string element1, std::string element2)
    {
        parent[find(element1)] = find(element2);
    }
};
int main()
{
    Graph graph;
    graph.addEdge("Computer Science", "Mathematics", 10);
    graph.addEdge("Computer Science", "Physics", 5);
    graph.addEdge("Computer Science", "Biology", 8);
    graph.addEdge("Mathematics", "Physics", 3);
    graph.addEdge("Physics", "Biology", 2);

    std::vector<Edge> edges;
    for (const auto &[department, neighbors] : graph.adjacencyList)
    {
        for (const Edge &edge : neighbors)
        {
            edges.push_back(edge);
        }
    }

    std::sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b)
              { return a.weight < b.weight; });

    UnionFind unionFind;
    for (const auto &[department, neighbors] : graph.adjacencyList)
    {
        unionFind.parent[department] = department;
    }

    Graph mst;

    for (const Edge &edge : edges)
    {
        std::string root1 = unionFind.find(edge.source);
        std::string root2 = unionFind.find(edge.destination);
        if (root1 != root2)
        {
            mst.addEdge(edge.source, edge.destination, edge.weight);
            unionFind.unionSet(root1, root2);
        }
    }

    std::cout << "Minimum spanning tree:" << std::endl;
    for (const auto &[department, neighbors] : mst.adjacencyList)
    {
        std::cout << department << ": ";
        for (const Edge &edge : neighbors)
        {
            std::cout << "(" << edge.destination << ", " << edge.weight << ") ";
        }
        std::cout << std::endl;
    }

    return 0;
}
