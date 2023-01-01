// represent a graph of college campususing adjacency list nodes shoud represent various departments and links should represent the distance between them use prims algorithm cpp

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <limits>
class Edge
{
public:
    std::string source;
    std::string destination;
    int weight;
    Edge() : source(""), destination(""), weight(0) {}
    Edge(std::string source, std::string destination, int weight) : source(source), destination(destination), weight(weight)
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
int main()
{
    Graph graph;
    graph.addEdge("Computer Science", "Mathematics", 10);
    graph.addEdge("Computer Science", "Physics", 5);
    graph.addEdge("Computer Science", "Biology", 8);
    graph.addEdge("Mathematics", "Physics", 3);
    graph.addEdge("Physics", "Biology", 2);

    Graph mst;
    std::unordered_set<std::string> includedVertices;
    std::string currentVertex = "Computer Science";
    includedVertices.insert(currentVertex);

    std::vector<Edge> mstEdges;
    while (includedVertices.size() < graph.adjacencyList.size())
    {
        int minWeight = std::numeric_limits<int>::max();
        Edge minEdge;
        for (const Edge &edge : graph.adjacencyList[currentVertex])
        {
            if (includedVertices.count(edge.destination) == 0 && edge.weight < minWeight)
            {
                minWeight = edge.weight;
                minEdge = edge;
            }
        }
        mstEdges.push_back(minEdge);
        includedVertices.insert(minEdge.destination);
        currentVertex = minEdge.destination;
    }
    for (const Edge &edge : mstEdges)
    {
        mst.addEdge(edge.source, edge.destination, edge.weight);
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
