@echo off
set build_path=vs2015.win32
rmdir /s/q %build_path%
mkdir %build_path%
pushd %build_path%
cmake .. -G"Visual Studio 14 2015"
start leetcode.sln
