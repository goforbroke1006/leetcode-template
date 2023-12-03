//
// Created by goforbroke on 10/23/23.
//

#ifndef LEETCODE_TRAINING_VECTOR_UTIL_H
#define LEETCODE_TRAINING_VECTOR_UTIL_H

#include <istream>
#include <ostream>
#include <sstream>
#include <vector>
#include <list>
#include <iomanip>

#define LIST_BEGIN '['
#define LIST_END ']'
#define LIST_DELIMITER ','

/**
 * Reading any vector.
 * Usage:
 *   std::vector<T> vector;
 *   std::cin >> number;
 * Input should be like:
 *   [3,2,3,1,2,4,5,5,6]
 *
 * @tparam T
 * @param is
 * @param out
 * @return
 */
template<class T>
std::istream &operator>>(std::istream &is, std::vector<T> &out) {
    std::string payload;
    is >> payload;

    if (payload.front() != LIST_BEGIN || payload.back() != LIST_END)
        throw std::logic_error("invalid vector input");

    payload.erase(0, 1);               // trim [
    payload.erase(payload.size() - 1); // trim ]

    std::stringstream ss;
    ss << payload;

    std::string str;
    while (std::getline(ss, str, LIST_DELIMITER)) {
        std::stringstream parsingSS;
        parsingSS << str;

        T value;
        parsingSS >> value;

        out.emplace_back(value);
    }

    return is;
}

template<class T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &vec) {
    for (const auto el: vec)
        os << el << " ";

    return os;
}

template<class T>
std::ostream &operator<<(std::ostream &os, const std::list<T> &list) {
    for (const auto el: list)
        os << el << " ";

    return os;
}

template<class T>
std::ostream &operator<<(std::ostream &os, const std::vector<std::vector<T>> &matrix) {
    for (const auto &row: matrix) {
        for (const auto &n: row) {
            os << std::setw(3) << n << " ";
        }
        os << std::endl;
    }
    return os;
}

#endif //LEETCODE_TRAINING_VECTOR_UTIL_H
