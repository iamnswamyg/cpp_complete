#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

class Node {
public:
    char data;

    Node(char data) : data(data) {}
};

class Graph {
private:
    std::vector<Node> nodes;
    std::vector<std::vector<int>> matrix;

public:
    Graph(int size) {
        matrix = std::vector<std::vector<int>>(size, std::vector<int>(size, 0));
    }

    void addNode(Node node) {
        nodes.push_back(node);
    }

    void addEdge(int src, int dst) {
        matrix[src][dst] = 1;
    }

    bool checkEdge(int src, int dst) {
        return matrix[src][dst] == 1;
    }

    void print() {
        std::cout << "  ";
        for (const Node& node : nodes) {
            std::cout << node.data << " ";
        }
        std::cout << std::endl;

        for (int i = 0; i < matrix.size(); i++) {
            std::cout << nodes[i].data << " ";
            for (int j = 0; j < matrix[i].size(); j++) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }

        
    }

    void breadthFirstSearch(int src) {
		std::queue<int> queue;
        int m=matrix.size();
        bool visited[m];
        std::fill(visited,visited+m,false);
        queue.push(src);
		visited[src] = true;
        while (!queue.empty()) {
            src = queue.front();
            queue.pop();
            std::cout << nodes[src].data << " = visited\n";
            for(int i = 0; i < matrix[src].size(); i++) {
				if(matrix[src][i] == 1 && !visited[i]) {
					queue.push(i);
					visited[i] = true;
				}
			}
        }

        
	}
	
};

int main() {
    Graph graph(5);

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

    graph.breadthFirstSearch(3);

    return 0;
}
