#pragma once

#include <vector>

struct QuadTree {
    // Definition for a QuadTree node.
    class Node {
    public:
        bool val;
        bool isLeaf;
        Node* topLeft;
        Node* topRight;
        Node* bottomLeft;
        Node* bottomRight;

        Node() {
            val = false;
            isLeaf = false;
            topLeft = NULL;
            topRight = NULL;
            bottomLeft = NULL;
            bottomRight = NULL;
        }

        Node(bool _val, bool _isLeaf) {
            val = _val;
            isLeaf = _isLeaf;
            topLeft = NULL;
            topRight = NULL;
            bottomLeft = NULL;
            bottomRight = NULL;
        }

        Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
            val = _val;
            isLeaf = _isLeaf;
            topLeft = _topLeft;
            topRight = _topRight;
            bottomLeft = _bottomLeft;
            bottomRight = _bottomRight;
        }
    };
    std::vector<std::vector<int>>& grid;
    Node* zero = new Node(false, true);
    Node* one = new Node(true, true);

    QuadTree(std::vector<std::vector<int>>& grid) : grid(grid) {}
    Node* construct() { return construct(0, 0, grid.size()); }
    Node* construct(unsigned row, unsigned col, unsigned dim);
};
