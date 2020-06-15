cmake_minimum_required(VERSION 3.15)
project(algorithm_dojo)

set(CMAKE_CXX_STANDARD 20)

add_executable(algorithm_dojo
        main.cpp
        pretty_print.h
        base.h
        binary_search.h
        binary_search.cpp
        template_matrix.h
#        2.add-two-numbers.cpp
#        116.populating-next-right-pointers-in-each-node.cpp
#        117.populating-next-right-pointers-in-each-node-ii.cpp
#        119.pascals-triangle-ii.cpp
#        124.binary-tree-maximum-path-sum.cpp
#        125.valid-palindrome.cpp
#        129.sum-root-to-leaf-numbers.cpp
#        132.palindrome-partitioning-ii.cpp
#        138.copy-list-with-random-pointer.cpp
#        146.lru-cache.cpp
#        187.repeated-dna-sequences.cpp
#        224.basic-calculator.cpp
#        226.invert-binary-tree.cpp
#        227.basic-calculator-ii.cpp
#        229.majority-element-ii.cpp
#        230.kth-smallest-element-in-a-bst.cpp
#        231.power-of-two.cpp
#        232.implement-queue-using-stacks.cpp
#        233.number-of-digit-one.cpp
#        234.palindrome-linked-list.cpp
#        235.lowest-common-ancestor-of-a-binary-search-tree.cpp
#        236.lowest-common-ancestor-of-a-binary-tree.cpp
#        237.delete-node-in-a-linked-list.cpp
#        240.search-a-2d-matrix-ii.cpp
#        241.different-ways-to-add-parentheses.cpp
#        242.valid-anagram.cpp
#        273.integer-to-english-words.cpp
#        274.h-index.cpp
#        275.h-index-ii.cpp
#        278.first-bad-version.cpp
#        282.expression-add-operators.cpp
#        284.peeking-iterator.cpp
#        292.nim-game.cpp
#        299.bulls-and-cows.cpp
#        321.create-maximum-number.cpp
#        327.count-of-range-sum.cpp
#        329.longest-increasing-path-in-a-matrix.cpp
#        330.patching-array.cpp
#        352.data-stream-as-disjoint-intervals.cpp
#        354.russian-doll-envelopes.cpp
#        355.design-twitter.cpp
#        357.count-numbers-with-unique-digits.cpp
#        363.max-sum-of-rectangle-no-larger-than-k.cpp
#        365.water-and-jug-problem.cpp
#        367.valid-perfect-square.cpp
#        368.largest-divisible-subset.cpp
#        371.sum-of-two-integers.cpp
#        372.super-pow.cpp
#        373.find-k-pairs-with-smallest-sums.cpp
#        374.guess-number-higher-or-lower.cpp
#        375.guess-number-higher-or-lower-ii.cpp
#        378.kth-smallest-element-in-a-sorted-matrix.cpp
        )

enable_testing()

find_package(GTest CONFIG REQUIRED)
target_link_libraries(algorithm_dojo
        PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)

add_test(AllTestsInMain algorithm_dojo)
