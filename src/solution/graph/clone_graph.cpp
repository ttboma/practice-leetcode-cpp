#include "graph/breadth_first_search.hpp"
#include "solution.hpp"

// Graph adapter for Node* based graphs (LeetCode style)
class GraphNodeAdapter {
public:
    using VertexType = GraphNode*;

    explicit GraphNodeAdapter(VertexType root) : root(root) {}

    std::vector<VertexType> adjacentVertices(VertexType u) const {
        if (!u)
            return {};
        return u->neighbors;
    }

private:
    VertexType root;
};

struct CloneGraphVisitor : public graph::DefaultBfsVisitor<GraphNode*> {
    mutable std::unordered_map<GraphNode*, GraphNode*> nodeMap;
    GraphNode* copiedRoot = nullptr;

    explicit CloneGraphVisitor(GraphNode* originalRoot) {
        nodeMap[originalRoot] = new GraphNode(originalRoot->val);
        copiedRoot = nodeMap[originalRoot];
    }

    void treeEdge(GraphNode* u, GraphNode* v) const {
        nodeMap[v] = new GraphNode(v->val);
        nodeMap[u]->neighbors.push_back(nodeMap[v]);
        nodeMap[v]->neighbors.push_back(nodeMap[u]);
    }

    void greyTarget(GraphNode* u, GraphNode* v) const {
        nodeMap[u]->neighbors.push_back(nodeMap[v]);
        nodeMap[v]->neighbors.push_back(nodeMap[u]);
    }
};

GraphNode* Solution::cloneGraph(GraphNode* node) {
    if (node == nullptr)
        return node;

    CloneGraphVisitor vis{node};
    std::unordered_map<GraphNode*, graph::Color> colorMap;
    graph::breadthFirstSearch(GraphNodeAdapter{node}, node, vis, colorMap);

    return vis.copiedRoot;
}
