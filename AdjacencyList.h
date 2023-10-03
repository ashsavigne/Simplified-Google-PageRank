class Graph {
public:

    struct Node{
        // Node class variables
        string name;
        forward_list<Node*> inNodes;
        int out;
        double r;
        double pr;

        explicit Node(string name) : name(std::move(name)), r(0), inNodes(), pr(0), out(0) {}

    };
private:
    // Graph class variables
    map<string, Node*> vertices;
public:
    // Constructor
    Graph() : vertices() {}

    void insertEdge(const string& to, const string& from);
    void PageRank(int n);
    void printGraph();

    // Destructor
    ~Graph();
};

