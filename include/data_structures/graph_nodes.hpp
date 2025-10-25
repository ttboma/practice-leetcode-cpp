#include <vector>

// Definition for a Node.
class GraphNode {
public:
    int val;
    std::vector<GraphNode*> neighbors;
    GraphNode() {
        val = 0;
        neighbors = std::vector<GraphNode*>();
    }
    GraphNode(int _val) {
        val = _val;
        neighbors = std::vector<GraphNode*>();
    }
    GraphNode(int _val, std::vector<GraphNode*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
