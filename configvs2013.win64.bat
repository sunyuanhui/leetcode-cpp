@echo off
set build_path=vs2013.win64
rmdir /s/q %build_path%
mkdir %build_path%
pushd %build_path%
cmake .. -G"Visual Studio 12 Win64"
start leetcode.sln