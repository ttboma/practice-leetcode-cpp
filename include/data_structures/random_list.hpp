#pragma once

#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class RandomList {
public:
    using size_type = std::size_t;

public:
    RandomList(Node* head) : head(head) {}
    RandomList(std::vector<std::vector<std::string>> items) {
        std::vector<Node*> nodes;
        for (const auto& item : items) {
            int val = std::stoi(item[0]);
            Node* node = new Node(val);
            nodes.push_back(node);
        }
        for (std::vector<Node*>::size_type i = 0; i != items.size(); ++i) {
            if (items[i][1] == "null")
                continue;
            int randomIndex = std::stoi(items[i][1]);
            if (static_cast<size_type>(randomIndex) < nodes.size()) {
                nodes[i]->random = nodes[randomIndex];
            }
        }

        for (std::vector<Node*>::size_type i = 1; i != items.size(); ++i) {
            nodes[i - 1]->next = nodes[i];
        }
        head = nodes.empty() ? nullptr : nodes[0];
    }
    ~RandomList() {
        std::vector<Node*> nodes;
        auto curr = head;
        while (curr != nullptr) {
            nodes.push_back(curr);
            curr = curr->next;
        }
        for (auto node : nodes) {
            delete node;
        }
    }

    bool operator==(const RandomList& other) const;

public:
    // overload operators ==
    bool empty() const { return head == nullptr; }
    Node* getHead() const { return head; }

private:
    Node* head;
};

std::ostream& operator<<(std::ostream& os, const RandomList& list);
