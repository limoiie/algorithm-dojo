cmake_minimum_required(VERSION 3.15)
project(algorithm_dojo)

set(CMAKE_CXX_STANDARD 17)

add_definitions(
    -D_CRT_SECURE_NO_WARNINGS    # used for ignore vs secure warning
    -D_SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING            # used for ignore tr1 namespace deprecation warning
    -D_SILENCE_CXX17_RESULT_OF_DEPRECATION_WARNING
    -D_SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING  # used for ignore deprecation warning about filesystem
    -DNOMINMAX
    -D_HAS_STD_BYTE=0
)

add_executable(algorithm_dojo
    main.cpp
    pretty_print.h
    base.h
    template_matrix.h
#    2.add-two-numbers.cpp
#    116.populating-next-right-pointers-in-each-node.cpp
#    117.populating-next-right-pointers-in-each-node-ii.cpp
#    119.pascals-triangle-ii.cpp
#    124.binary-tree-maximum-path-sum.cpp
#    125.valid-palindrome.cpp
#    129.sum-root-to-leaf-numbers.cpp
#    132.palindrome-partitioning-ii.cpp
#    138.copy-list-with-random-pointer.cpp
#    146.lru-cache.cpp
#    187.repeated-dna-sequences.cpp
#    224.basic-calculator.cpp
#    226.invert-binary-tree.cpp
#    227.basic-calculator-ii.cpp
#    229.majority-element-ii.cpp
#    230.kth-smallest-element-in-a-bst.cpp
#    231.power-of-two.cpp
#    232.implement-queue-using-stacks.cpp
#    233.number-of-digit-one.cpp
#    234.palindrome-linked-list.cpp
#    235.lowest-common-ancestor-of-a-binary-search-tree.cpp
#    236.lowest-common-ancestor-of-a-binary-tree.cpp
#    237.delete-node-in-a-linked-list.cpp
#    240.search-a-2d-matrix-ii.cpp
#    241.different-ways-to-add-parentheses.cpp
#    242.valid-anagram.cpp
#    273.integer-to-english-words.cpp
#    274.h-index.cpp
#    275.h-index-ii.cpp
#    278.first-bad-version.cpp
#    282.expression-add-operators.cpp
#    284.peeking-iterator.cpp
#    292.nim-game.cpp
#    299.bulls-and-cows.cpp
#    321.create-maximum-number.cpp
#    327.count-of-range-sum.cpp
#    329.longest-increasing-path-in-a-matrix.cpp
#    383.ransom-note.cpp
#    384.shuffle-an-array.cpp
#    385.mini-parser.cpp
#    386.lexicographical-numbers.cpp
#    387.first-unique-character-in-a-string.cpp
#    388.longest-absolute-file-path.cpp
#    389.find-the-difference.cpp
#    409.longest-palindrome.cpp
#    410.split-array-largest-sum.cpp
#    421.maximum-xor-of-two-numbers-in-an-array.cpp
#    423.reconstruct-original-digits-from-english.cpp
#    424.longest-repeating-character-replacement.cpp
#    435.non-overlapping-intervals.cpp
#    437.path-sum-iii.cpp
#    438.find-all-anagrams-in-a-string.cpp
#    447.number-of-boomerangs.cpp
#    446.arithmetic-slices-ii-subsequence.cpp
#    451.sort-characters-by-frequency.cpp
#    452.minimum-number-of-arrows-to-burst-balloons.cpp
#    453.minimum-moves-to-equal-array-elements.cpp
#    467.unique-substrings-in-wraparound-string.cpp
#    481.magical-string.cpp
#    482.license-key-formatting.cpp
    483.smallest-good-base.cpp
#    516.longest-palindromic-subsequence.cpp
#    517.super-washing-machines.cpp
#    523.continuous-subarray-sum.cpp
#    552.student-attendance-record-ii.cpp
    )

enable_testing()

find_package(GTest CONFIG REQUIRED)
target_link_libraries(algorithm_dojo
    PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)

add_test(AllTestsInMain algorithm_dojo)
