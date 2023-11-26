//
// Created by goforbroke on 10/23/23.
//

#ifndef LEETCODE_TRAINING_VECTOR_UTIL_H
#define LEETCODE_TRAINING_VECTOR_UTIL_H

#include <istream>
#include <ostream>
#include <vector>
#include <list>
#include <iomanip>

/**
 * Reading any vector.
 * Usage:
 *   std::vector<int> numbers;
 *   std::cin >> number;
 * Input should be like:
 *   5
 *   0 1 2 3 4
 * where is "5" is expected length, and 0 1 2 3 4 - vector's elements.
 *
 * @tparam T
 * @param is
 * @param vecOut
 * @return
 */
template<class T>
std::istream &operator>>(std::istream &is, std::vector<T> &vecOut) {
    size_t length;
    is >> length;

    vecOut.reserve(length);

    for (size_t idx = 0; idx < length; ++idx) {
        T value;
        is >> value;
        vecOut.emplace_back(value);
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
