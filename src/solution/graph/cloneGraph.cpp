#include "graph/breadthFirstSearch.hpp"
#include "solution.hpp"

// Graph adapter for Node* based graphs (LeetCode style)
class GraphNodeAdapter {
public:
    using VertexType = GraphNode*;

    explicit GraphNodeAdapter(VertexType root) : root_(root) {}

    std::vector<VertexType> adjacent_vertices(VertexType u) const {
        if (!u)
            return {};
        return u->neighbors;
    }

private:
    VertexType root_;
};

struct CloneGraphVisitor : public graph::DefaultBfsVisitor<GraphNode*> {
    mutable std::unordered_map<GraphNode*, GraphNode*> nodeMap;
    GraphNode* copiedRoot = nullptr;

    explicit CloneGraphVisitor(GraphNode* originalRoot) {
        nodeMap[originalRoot] = new GraphNode(originalRoot->val);
        copiedRoot = nodeMap[originalRoot];
    }

    void tree_edge(GraphNode* u, GraphNode* v) const {
        nodeMap[v] = new GraphNode(v->val);
        nodeMap[u]->neighbors.push_back(nodeMap[v]);
        nodeMap[v]->neighbors.push_back(nodeMap[u]);
    }

    void discover_grey_target(GraphNode* u, GraphNode* v) const {
        nodeMap[u]->neighbors.push_back(nodeMap[v]);
        nodeMap[v]->neighbors.push_back(nodeMap[u]);
    }
};

GraphNode* Solution::cloneGraph(GraphNode* node) {
    if (node == nullptr)
        return node;

    CloneGraphVisitor vis{node};
    std::unordered_map<GraphNode*, graph::Color> colorMap;
    graph::breadth_first_search(GraphNodeAdapter{node}, node, vis, colorMap);

    return vis.copiedRoot;
}
