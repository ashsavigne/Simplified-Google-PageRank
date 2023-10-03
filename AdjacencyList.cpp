#include "AdjacencyList.h"
#include <iomanip>


void Graph::insertEdge(const string& to, const string& from){
    // To Do: add to and from node to map and add from node to new nodes list of in-nodes

    // if nodes to and from dne
    if (vertices.find(to) == vertices.end() && vertices.find(from) == vertices.end()){
        Node* newTo = new Node(to); // O(1)
        Node* newFrom = new Node(from); // O(1)
        newTo->inNodes.push_front(newFrom); // O(1)
        newFrom->out++; // O(1)
        vertices[to] = newTo; // O (logS) S = size map
        vertices[from] = newFrom; // O (logS) S = size map
    }

    // if node to dne
    else if (vertices.find(to) == vertices.end() && vertices.find(from) != vertices.end()){
        Node* newTo = new Node(to);
        newTo->inNodes.push_front(vertices[from]);
        vertices[to] = newTo;
        vertices[from]->out++;
    }

    //if node from dne
    else if (vertices.find(to) != vertices.end() && vertices.find(from) == vertices.end()){
        Node* newFrom = new Node(from);
        vertices[to]->inNodes.push_front(newFrom);
        vertices[from] = newFrom;
        vertices[from]->out++;
    }

    // if both nodes exist
    else if (vertices.find(to) != vertices.end() && vertices.find(from) != vertices.end()){
        vertices[to]->inNodes.push_front(vertices[from]);
        vertices[from]->out++;
    }
    // time: O(log map size)

}

void Graph::PageRank(int n) {
// To Do: apply formula: rank(nodeN) = SIGMA(rank(node i)/ out-degree(node i))

    // find initial rank
    for (const auto &itr: vertices) { // O (k)
        itr.second->r = 1.0f / double(vertices.size());
    }

    while (n > 1){ // O(N)
        for (const auto& itr: vertices) { // O(K) : K = map keys
            for (const auto& adj: itr.second->inNodes){ // O(I) I = keys in nodes
                    itr.second->pr += (adj->r / double(adj->out));
            }
        }
        for (const auto &itr: vertices) { // O(K) : k = map Keys
            itr.second->r = itr.second->pr;
            itr.second->pr = 0;
        }
        n--;
    }
}


void Graph::printGraph(){
    // To Do: print name and pagerank with two decimals
    for (const auto& itr: vertices) { // O(k) : K = map keys
        cout << std::fixed;
        cout << std::setprecision(2);
        cout << itr.second->name << ' ' << itr.second->r << endl;
    }
}

Graph::~Graph() {
    // To Do: delete all nodes
    for (const auto& itr : vertices){ // O(k) : K = map keys
        delete itr.second;
    }
}
