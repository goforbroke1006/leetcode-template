//
// Created by goforbroke on 9/24/23.
//

#ifndef LEETCODE_TRAINING_LISTNODE_H
#define LEETCODE_TRAINING_LISTNODE_H

#include <iostream>
#include <istream>
#include <ostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *readList(size_t length) {
    auto *head = new ListNode();
    auto *last = head;

    for (size_t idx = 0; idx < length; ++idx) {
        int number;
        std::cin >> number;

        last->next = new ListNode(number);
        last = last->next;
    }

    auto *result = head->next;
    delete head;
    return result;
}

ListNode *readList(std::istream &is, size_t length) {
    auto *head = new ListNode();
    auto *last = head;

    for (size_t idx = 0; idx < length; ++idx) {
        int number;
        is >> number;

        last->next = new ListNode(number);
        last = last->next;
    }

    auto *result = head->next;
    delete head;
    return result;
}

ListNode *readLenAndListWithLen(std::istream &is) {
    size_t length;
    is >> length;

    auto *head = new ListNode();
    auto *last = head;

    for (size_t idx = 0; idx < length; ++idx) {
        int number;
        is >> number;

        last->next = new ListNode(number);
        last = last->next;
    }

    auto *result = head->next;
    delete head;
    return result;
}

std::ostream &operator<<(std::ostream &os, const ListNode *head) {
    while (true) {
        if (nullptr == head)
            break;
        os << head->val << " ";
        head = head->next;
    }

    return os;
}

#endif //LEETCODE_TRAINING_LISTNODE_H
