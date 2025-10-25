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
    void discover_vertex(Vertex u) const {}

    // Called on every out-edge of each vertex after it is discovered
    void examine_edge(Vertex u, Vertex v) const {}

    // Called on each edge as it becomes a member of the edges that form the search tree
    void tree_edge(Vertex u, Vertex v) const {}

    // Called on back edges (creates a cycle in undirected graphs)
    void back_edge(Vertex u, Vertex v) const {}

    // Called on forward or cross edges for directed graphs
    void forward_or_cross_edge(Vertex u, Vertex v) const {}

    // Called on each vertex after all of its out-edges have been examined
    void finish_vertex(Vertex u) const {}
};

// Recursive DFS implementation (traditional and clean)
template <typename Graph, typename Vertex, typename Visitor, typename ColorMap>
void depth_first_search(const Graph& g, Vertex u, Visitor& vis, ColorMap& color) {
    color[u] = Color::Gray;
    vis.discover_vertex(u);

    // Examine all adjacent vertices
    for (auto v : g.adjacent_vertices(u)) {
        vis.examine_edge(u, v);

        if (color[v] == Color::White) {
            vis.tree_edge(u, v);
            depth_first_search(g, v, vis, color);
        } else if (color[v] == Color::Gray) {
            vis.back_edge(u, v);
        } else {
            vis.forward_or_cross_edge(u, v);
        }
    }

    color[u] = Color::Black;
    vis.finish_vertex(u);
}

}  // namespace graph
