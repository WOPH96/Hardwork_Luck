#!bin/env bash

h="/home/runner/HardworkLuck/"
site="baekjoon"
category="greedy"
number="11000"
src_dir="${h}/${site}/${category}/${category}-${number}/C++/"

# src_dir="/home/runner/HardworkLuck/baekjoon/graph_search/graph_search-1753/C++"
cd ${src_dir}
g++ -std=c++17 -w -o main ${src_dir}/*.cpp
./main
rm -rf ${src_dir}/main