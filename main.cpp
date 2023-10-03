#include <iostream>
#include "AdjacencyList.h"
#include <unordered_map>

int main()
{
    // accept input
    int no_of_lines, power_iterations;
    std::string from, to;
    std::cin >> no_of_lines;
    std::cin >> power_iterations;

    // create graph
    unordered_map<string, vector<string>> graph;
    for(int i = 0; i < no_of_lines; i++){ // O(K) K = number of map keys
        std::cin >> from;
        std::cin >> to;
        graph[to].push_back(from);
        if (graph.find(from) == graph.end())
            graph[from] = {};
    }

    //Create a graph object
    Graph newGraph;
    for (const auto& i : graph){ //O(K) K = graph keys
        for (const auto& j : i.second) // O(I) I = num in nodes
            newGraph.insertEdge(i.first, j);
    }

    // find page rank
    newGraph.PageRank(power_iterations);

    // print graph
    newGraph.printGraph();
}
