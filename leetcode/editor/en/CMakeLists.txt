cmake_minimum_required(VERSION 3.15)
project(algorithm_dojo)

set(CMAKE_CXX_STANDARD 20)

add_executable(algorithm_dojo
        main.cpp
        pretty_print.h
        base.h
        2.add-two-numbers.cpp
        299.bulls-and-cows.cpp
        321.create-maximum-number.cpp
        327.count-of-range-sum.cpp
        329.longest-increasing-path-in-a-matrix.cpp
        )

enable_testing()

find_package(GTest CONFIG REQUIRED)
target_link_libraries(algorithm_dojo
        PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)

add_test(AllTestsInMain algorithm_dojo)
