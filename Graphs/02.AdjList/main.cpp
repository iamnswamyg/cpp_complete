#include <iostream>
#include <vector>
#include <list>

class Node {
public:
    char data;

    Node(char data) : data(data) {}
};

class Graph {
private:
    std::vector<std::list<Node>> alist;

public:
    Graph() {}

    void addNode(Node node) {
        std::list<Node> currentList;
        currentList.push_back(node);
        alist.push_back(currentList);
    }

    void addEdge(int src, int dst) {
        std::list<Node>& currentList = alist[src];
        Node dstNode = alist[dst].front();
        currentList.push_back(dstNode);
    }

    bool checkEdge(int src, int dst) {
        std::list<Node>& currentList = alist[src];
        Node dstNode = alist[dst].front();

        for (const Node& node : currentList) {
            if (node.data == dstNode.data) {
                return true;
            }
        }
        return false;
    }

    void print() {
        for (const std::list<Node>& currentList : alist) {
            for (const Node& node : currentList) {
                std::cout << node.data << " -> ";
            }
            std::cout << std::endl;
        }
    }
};


int main() {
    Graph graph;

    graph.addNode(Node('A'));
    graph.addNode(Node('B'));
    graph.addNode(Node('C'));
    graph.addNode(Node('D'));
    graph.addNode(Node('E'));

    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(1, 4); // I forgot this line in the video
    graph.addEdge(2, 3);
    graph.addEdge(2, 4);
    graph.addEdge(4, 0);
    graph.addEdge(4, 2);

    graph.print();

    std::cout << std::endl;
    std::cout <<std::boolalpha<<graph.checkEdge(1,2)<< std::endl;

    return 0;
}
