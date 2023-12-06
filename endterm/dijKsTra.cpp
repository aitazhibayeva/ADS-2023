#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// Structure to represent edges and their weights in the graph
struct Edge {
    int destination;
    int weight;
};

// Function to implement Dijkstra's algorithm
vector<int> dijkstra(const vector<vector<Edge>>& graph, int start) {
    int numVertices = graph.size();
    vector<int> distances(numVertices, numeric_limits<int>::max()); // Initialize distances with infinity
    distances[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start}); // {distance, vertex}

    while (!pq.empty()) {
        int currentVertex = pq.top().second;
        int currentDistance = pq.top().first;
        pq.pop();

        // Check if the current distance is greater than the stored distance
        if (currentDistance > distances[currentVertex]) {
            continue;
        }

        // Explore neighbors and update distances
        for (const Edge& neighbor : graph[currentVertex]) {
            int neighborVertex = neighbor.destination;
            int edgeWeight = neighbor.weight;

            int newDistance = distances[currentVertex] + edgeWeight;

            if (newDistance < distances[neighborVertex]) {
                distances[neighborVertex] = newDistance;
                pq.push({newDistance, neighborVertex});
            }
        }
    }

    return distances;
}

int main() {
    int numVertices = 6; // Number of vertices in the graph

    // Adjacency list representation of the graph
    vector<vector<Edge>> graph(numVertices);
    graph[0].push_back({1, 4});
    graph[0].push_back({2, 2});
    graph[1].push_back({2, 5});
    graph[1].push_back({3, 10});
    graph[2].push_back({4, 3});
    graph[3].push_back({5, 2});
    graph[4].push_back({5, 1});

    int startVertex = 0; // Define the starting vertex

    vector<int> shortestDistances = dijkstra(graph, startVertex);

    // Printing shortest distances from start to all vertices
    for (int i = 0; i < numVertices; ++i) {
        cout << "Shortest distance from vertex " << startVertex << " to vertex " << i << " is: ";
        if (shortestDistances[i] == numeric_limits<int>::max()) {
            cout << "INFINITY" << endl;
        } else {
            cout << shortestDistances[i] << endl;
        }
    }

    return 0;
}
