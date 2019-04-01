#include "test_hforest.hh"
#include "test_htree.hh"
#include "hforest.hh"
#include <stdio.h>
#include <ostream>
#include <iostream>
#include "htree.hh"

int test_forest(){

    value_t value_all[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    key_t keys1[] = {1, 2, 3, 4}; // second greatest root node tree, ie. root node has the 2nd greatest value of the rest
    const auto len1 = 4;
    HTree::tree_ptr_t tree1 = make_tree(keys1, keys1 + len1, value_all + 1, value_all + 1 + len1); 

    key_t keys2[] = {5, 6, 7, 8, 9, 10}; // last greatest root node tree
    const auto len2 = 6;
    HTree::tree_ptr_t tree2 = make_tree(keys2, keys2 + len2, value_all, value_all + len2);

    key_t keys3[] = {11, 12, 13}; // first greatest root node tree
    const auto len3 = 3;
    HTree::tree_ptr_t tree3 = make_tree(keys3, keys3 + len3, value_all + 2, value_all + 2 + len3);
    
    HForest forest;                             // create and check size of forest
    std::cout << "size: " << forest.size() << std::endl;                    // 0

    forest.add_tree(tree1);                     // add tree 1 (2nd great) and check size
    std::cout << "size: " << forest.size() << std::endl;                    // 1

    forest.add_tree(tree2);                     // add tree 2 (3rd great) and check size, pop, check size again
    std::cout << "size: " << forest.size() << std::endl;                    // 2
    std::cout << "pop : " << forest.pop_tree()->get_value() << std::endl;   // 2
    std::cout << "size: " << forest.size() << std::endl;                    // 1

    forest.add_tree(tree3);     // set up for tie
    forest.add_tree(tree3);
    std::cout << "\nsize: " << forest.size() << std::endl;                  // 3
    std::cout << "pop : " << forest.pop_tree()->get_value() << std::endl;   // 3
    std::cout << "pop : " << forest.pop_tree()->get_value() << std::endl;   // 3 since there are two trees 3 in head
    std::cout << "size: " << forest.size() << std::endl;                    // 1 by two pops

    return 0;
}
