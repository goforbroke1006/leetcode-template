//
// Created by goforbroke on 9/25/23.
//

#ifndef LEETCODE_TRAINING_TREENODE_H
#define LEETCODE_TRAINING_TREENODE_H

#include <queue>
#include <istream>
#include <sstream>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode() : val(0), left(nullptr), right(nullptr) {}

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    explicit TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#define NODE_NULL "null"

std::istream &operator>>(std::istream &is, TreeNode *&root) {
    std::string payload;

    while (true) {
        std::getline(is, payload);
        if (!payload.empty()) break;
    }

    std::stringstream ss;
    ss << payload;

    std::queue<TreeNode **> nodesQ;
    nodesQ.push(&root);

    std::string chunk;
    while (std::getline(ss, chunk, ' ')) {
        if (NODE_NULL == chunk) {
            *nodesQ.front() = nullptr;
            nodesQ.pop();
            continue;
        }

        *nodesQ.front() = new TreeNode(atoi(chunk.c_str()));

        nodesQ.push(&(*nodesQ.front())->left);
        nodesQ.push(&(*nodesQ.front())->right);

        nodesQ.pop();
    }

    while (!nodesQ.empty()) nodesQ.pop();

    return is;
}

void readNode(std::istream &is, TreeNode **nodePP) {
    std::string value;
    is >> value;
    if ("null" == value) {
        *nodePP = nullptr;
        return;
    }

    *nodePP = new TreeNode(atoi(value.c_str()));
}

TreeNode *readTree(std::istream &is, size_t length) {
    if (0 == length)
        return nullptr;

    TreeNode *root = nullptr;

    std::queue<TreeNode **> q;
    q.push(&root);

    for (size_t idx = 0; idx < length; ++idx) {
        auto **node = q.front();
        q.pop();

        readNode(is, node);
        if (nullptr == *node)
            continue;

        q.push(&(*node)->left);
        q.push(&(*node)->right);
    }

    return root;
}

TreeNode *readTree(size_t length) {
    return readTree(std::cin, length);
}

#endif //LEETCODE_TRAINING_TREENODE_H
