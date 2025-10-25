#pragma once

#include <functional>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "graph_common.hpp"

namespace graph {

// BFS Visitor concept (similar to BGL's BFSVisitor)
template <typename Vertex>
struct DefaultBfsVisitor {
    // Called when a vertex is encountered for the first time
    void discover_vertex(Vertex u) const {}

    // Called when a vertex is removed from the queue
    void examine_vertex(Vertex u) const {}

    // Called on every out-edge of each vertex after it is discovered
    void examine_edge(Vertex u, Vertex v) const {}

    // Called on each edge as it becomes a member of the edges that form the search tree
    void tree_edge(Vertex u, Vertex v) const {}

    // Called when a gray target vertex is encountered
    void grey_target(Vertex u, Vertex v) const {}

    // Called when a black target vertex is encountered
    void black_target(Vertex u, Vertex v) const {}

    // Called on back or cross edges for directed graphs
    void non_tree_edge(Vertex u, Vertex v) const {}

    // Called on each vertex after all of its out-edges have been examined
    void finish_vertex(Vertex u) const {}
};

// BGL-style breadth_first_search algorithm
template <typename Graph, typename Vertex, typename Visitor, typename ColorMap>
void breadth_first_search(const Graph& g, Vertex start, Visitor& vis, ColorMap& color) {
    std::queue<Vertex> Q;

    // Initialize all vertices as white (unvisited)
    color[start] = Color::Gray;
    vis.discover_vertex(start);

    Q.push(start);
    while (!Q.empty()) {
        Vertex u = Q.front();
        Q.pop();

        // Examine all adjacent vertices
        for (auto v : g.adjacent_vertices(u)) {
            vis.examine_edge(u, v);

            if (color[v] == Color::White) {
                vis.tree_edge(u, v);
                color[v] = Color::Gray;
                vis.discover_vertex(v);
                Q.push(v);
            } else {
                vis.non_tree_edge(u, v);
                if (color[v] == Color::Gray) {
                    vis.grey_target(u, v);
                } else {
                    vis.black_target(u, v);
                }
            }
        }

        color[u] = Color::Black;
        vis.finish_vertex(u);
    }
}

}  // namespace graph
