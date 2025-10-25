#include "solution.hpp"

QuadTree::Node* QuadTree::construct(unsigned row, unsigned col, unsigned dim) {
    if (dim == 1) {
        return grid[row][col] == 1 ? one : zero;
    } else {
        dim /= 2;
        Node* topLeft = construct(row, col, dim);
        Node* topRight = construct(row, col + dim, dim);
        Node* bottomRight = construct(row + dim, col + dim, dim);
        Node* bottomLeft = construct(row + dim, col, dim);
        if (topRight == topLeft && topLeft == bottomLeft && bottomLeft == bottomRight) {
            return topRight;
        }
        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    }
}

QuadTree::Node* Solution::construct(std::vector<std::vector<int>>& grid) {
    return QuadTree(grid).construct();
}
