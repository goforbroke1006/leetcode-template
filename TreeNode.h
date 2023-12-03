//
// Created by goforbroke on 9/25/23.
//

#ifndef LEETCODE_TRAINING_TREENODE_H
#define LEETCODE_TRAINING_TREENODE_H

#include <queue>
#include <istream>
#include <ostream>
#include <sstream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode() : val(0), left(nullptr), right(nullptr) {}

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    explicit TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

    virtual ~TreeNode() {
        delete this->left;
        delete this->right;
    }
};

#define TREE_BEGIN '['
#define TREE_END ']'
#define TREE_NODE_NULL "null"
#define TREE_NODE_DELIMITER ','

/**
 * Read tree from input stream.
 * Expected format "[5,3,6,2,4,null,7]"
 * @param is
 * @param root
 * @return
 */
std::istream &operator>>(std::istream &is, TreeNode *&root) {
    std::string payload;
    is >> payload;

    if (payload.front() != TREE_BEGIN || payload.back() != TREE_END)
        throw std::logic_error("invalid tree input");

    payload.erase(0, 1);               // trim [
    payload.erase(payload.size() - 1); // trim ]

    std::stringstream ss;
    ss << payload;

    std::queue<TreeNode **> nodesQ;
    nodesQ.push(&root);

    std::string chunk;
    while (std::getline(ss, chunk, TREE_NODE_DELIMITER)) {
        if (TREE_NODE_NULL == chunk) {
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

std::ostream &operator<<(std::ostream &os, const TreeNode *node) {
    if (nullptr == node) {
        os << TREE_BEGIN << TREE_END;
        return os;
    }

    std::queue<const TreeNode *> qqq;
    qqq.push(node);

    std::vector<std::string> values;

    while (!qqq.empty()) {
        const auto *ptr = qqq.front();
        qqq.pop();

        if (nullptr == ptr) {
            values.emplace_back(TREE_NODE_NULL);
        } else {
            values.emplace_back(std::to_string(ptr->val));

            if (nullptr != ptr->left || nullptr != ptr->right) {
                qqq.push(ptr->left);
                qqq.push(ptr->right);
            }
        }
    }

    os << TREE_BEGIN;
    for (size_t idx = 0; idx < values.size(); ++idx) {
        os << values[idx];
        if (idx < values.size() - 1)
            os << TREE_NODE_DELIMITER;
    }
    os << TREE_END;

    return os;
}

#endif //LEETCODE_TRAINING_TREENODE_H
