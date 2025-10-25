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
    void discoverVertex(Vertex u) const {}

    // Called when a vertex is removed from the queue
    void examineVertex(Vertex u) const {}

    // Called on every out-edge of each vertex after it is discovered
    void examineEdge(Vertex u, Vertex v) const {}

    // Called on each edge as it becomes a member of the edges that form the search tree
    void treeEdge(Vertex u, Vertex v) const {}

    // Called when a gray target vertex is encountered
    void greyTarget(Vertex u, Vertex v) const {}

    // Called when a black target vertex is encountered
    void blackTarget(Vertex u, Vertex v) const {}

    // Called on back or cross edges for directed graphs
    void nonTreeEdge(Vertex u, Vertex v) const {}

    // Called on each vertex after all of its out-edges have been examined
    void finishVertex(Vertex u) const {}
};

// BGL-style breadthFirstSearch algorithm
template <typename Graph, typename Vertex, typename Visitor, typename ColorMap>
void breadthFirstSearch(const Graph& g, Vertex start, Visitor& vis, ColorMap& color) {
    std::queue<Vertex> Q;

    // Initialize all vertices as white (unvisited)
    color[start] = Color::Gray;
    vis.discoverVertex(start);

    Q.push(start);
    while (!Q.empty()) {
        Vertex u = Q.front();
        Q.pop();

        // Examine all adjacent vertices
        for (auto v : g.adjacentVertices(u)) {
            vis.examineEdge(u, v);

            if (color[v] == Color::White) {
                vis.treeEdge(u, v);
                color[v] = Color::Gray;
                vis.discoverVertex(v);
                Q.push(v);
            } else {
                vis.nonTreeEdge(u, v);
                if (color[v] == Color::Gray) {
                    vis.greyTarget(u, v);
                } else {
                    vis.blackTarget(u, v);
                }
            }
        }

        color[u] = Color::Black;
        vis.finishVertex(u);
    }
}

}  // namespace graph
