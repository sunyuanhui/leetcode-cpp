@echo off
set build_path=build
rmdir /s/q %build_path%
mkdir %build_path%
cd %build_path%
cmake ..
start leetcode.sln
