project(leetcode)

# setting the minimum required CMake version to 2.8.12
# is required for support vs2013 project
cmake_minimum_required(VERSION 2.8.12)

if(MSVC)
    # c++11中std::tuple是固定参数，需要指定个数，gtest中使用到10个参数
    add_definitions(-D_VARIADIC_MAX=10)
endif()

set_property(GLOBAL PROPERTY USE_FOLDERS On) # cmake生成vs解决方案时的项目文件夹
set_property(GLOBAL PROPERTY GLOBAL_DEPENDS_NO_CYCLES TRUE)

set(TARGET_DIR ${PROJECT_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${TARGET_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${TARGET_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${TARGET_DIR}/bin)
set(CMAKE_OUTPUT_DIRECTORY_INTDIR ${TARGET_DIR}/bin/${CMAKE_CFG_INTDIR})

add_subdirectory(gmock)
add_subdirectory("Min Stack")

set(ALL_TEST 
    MinStack
    )

foreach(ONE_TEST ${ALL_TEST})
    add_test(NAME ${ONE_TEST} COMMAND ${ONE_TEST} --config $<CONFIGURATION>
                          --gtest_output=xml:/Testing/Temporary/${ONE_TEST}.xml 
                          --gtest_shuffle 
                          --gtest_random_seed=0)	#shuffle与random_seed用来乱序执行用例
endforeach()
