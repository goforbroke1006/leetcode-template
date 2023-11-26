#!/usr/bin/env bash

# Remove old Clang versions
sudo apt remove --autoremove \
  clang-14 lldb-14 lld-14 clangd-14 \
  clang-15 lldb-15 lld-15 clangd-15 \
  clang-16 lldb-16 lld-16 clangd-16

#
# Install Clang 17
#
wget https://apt.llvm.org/llvm.sh
chmod u+x llvm.sh
sudo ./llvm.sh 17
clang-17 --version

echo "CMAKE_C_COMPILER   = /usr/bin/clang-17"
echo "CMAKE_CXX_COMPILER = /usr/bin/clang++-17"

#
# Install Cmake
#
sudo apt remove cmake -y || true
sudo snap install cmake --classic || sudo snap refresh cmake --classic
source ~/.bashrc
cmake --version

#
# Ninja Build
#
sudo apt-get update
sudo apt-get install -y ninja-build

echo "CMAKE_MAKE_PROGRAM = ninja"

#
# Build project
#
cmake \
  -DCMAKE_BUILD_TYPE=Debug \
  -DCMAKE_MAKE_PROGRAM=ninja \
  -DCMAKE_C_COMPILER=clang-17 -DCMAKE_CXX_COMPILER=clang++-17 \
  -G Ninja -S ./ -B ./cmake-build-debug

#(cd ./cmake-build-debug && ctest)
(cd ./cmake-build-debug && ninja test)
