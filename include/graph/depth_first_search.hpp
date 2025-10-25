#pragma once

#include <algorithm>
#include <functional>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "graph_common.hpp"

namespace graph {

// DFS Visitor concept (similar to BGL's DFSVisitor)
template <typename Vertex>
struct DefaultDfsVisitor {
    // Called when a vertex is encountered for the first time
    void discoverVertex(Vertex u) const {}

    // Called on every out-edge of each vertex after it is discovered
    void examineEdge(Vertex u, Vertex v) const {}

    // Called on each edge as it becomes a member of the edges that form the search tree
    void treeEdge(Vertex u, Vertex v) const {}

    // Called on back edges (creates a cycle in undirected graphs)
    void backEdge(Vertex u, Vertex v) const {}

    // Called on forward or cross edges for directed graphs
    void forwardOrCrossEdge(Vertex u, Vertex v) const {}

    // Called on each vertex after all of its out-edges have been examined
    void finishVertex(Vertex u) const {}
};

// Recursive DFS implementation (traditional and clean)
template <typename Graph, typename Vertex, typename Visitor, typename ColorMap>
void depthFirstSearch(const Graph& g, Vertex u, Visitor& vis, ColorMap& color) {
    color[u] = Color::Gray;
    vis.discoverVertex(u);

    // Examine all adjacent vertices
    for (auto v : g.adjacentVertices(u)) {
        vis.examineEdge(u, v);

        if (color[v] == Color::White) {
            vis.treeEdge(u, v);
            depthFirstSearch(g, v, vis, color);
        } else if (color[v] == Color::Gray) {
            vis.backEdge(u, v);
        } else {
            vis.forwardOrCrossEdge(u, v);
        }
    }

    color[u] = Color::Black;
    vis.finishVertex(u);
}

}  // namespace graph
