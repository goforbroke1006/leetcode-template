#!/usr/bin/env bash

read -p 'Task number: ' task_number
read -p 'Task name:   ' task_name

task_number=$(printf %04d "${task_number}")

task_name="${task_name// /-}"
task_name=$(echo "${task_name}" | awk '{print tolower($0)}')

task_link="https://leetcode.com/problems/${task_name}/"
project_name="problem-${task_number}-${task_name}"

if [ -d "./${project_name}" ] ; then
  echo "ERROR: directory ${project_name} already exists"
  exit 1
fi

echo '========== ========== ========== =========='
echo "Directory: ./${project_name}"
echo '========== ========== ========== =========='

mkdir "./${project_name}"

cat >"./${project_name}/CMakeLists.txt" <<EOL
# # ${task_number}
# ${task_link}

project(${project_name})

add_executable(\${PROJECT_NAME} main.cpp)
EOL

username=$(whoami)
current_date=$(date +'%d/%m/%Y')

cat >"./${project_name}/main.cpp" <<EOL
//
// Created by ${username} on ${current_date}.
//
// # ${task_number}
// ${task_link}

#include <iostream>

#define DEBUG 1

#include "../util.h"
#include "Solution.h"

int main() {
    size_t samplesCount;
    std::cin >> samplesCount;

    for (size_t sampleIDx = 0; sampleIDx < samplesCount; ++sampleIDx) {
        std::vector<int> numbers;
        std::cin >> numbers;

        int target;
        std::cin >> target;

        const auto &result = Solution().twoSum(numbers, target);
        std::cout << result << std::endl;
    }

    return 0;
}
EOL

touch "./${project_name}/input.txt"

cat >"./${project_name}/Solution.h" <<EOL
//
// Created by ${username} on ${current_date}.
//
// # ${task_number}
// ${task_link}

#ifndef LEETCODE_TRAINING_SOLUTION_H
#define LEETCODE_TRAINING_SOLUTION_H

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> twoSum(const std::vector<int> &nums, int target) {

#ifdef DEBUG
        std::cout << "Find values " << std::endl;
#endif

        return {};
    }
};

#endif //LEETCODE_TRAINING_SOLUTION_H
EOL

echo "add_subdirectory(./${project_name})" >> ./CMakeLists.txt

# update build
cmake \
  -DCMAKE_BUILD_TYPE=Debug \
  -DCMAKE_MAKE_PROGRAM=ninja \
  -G Ninja -S "./" -B "./cmake-build-debug"
