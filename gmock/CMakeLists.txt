
add_library(gmock
    gmock_main.cc
    gmock-gtest-all.cc
    gtest/gtest.h
    gmock/gmock.h
)
target_include_directories(gmock PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
