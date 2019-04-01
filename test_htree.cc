#include <assert.h>
#include <ostream>
#include <iostream>
#include <stdio.h>
#include "test_htree.hh"

int test_tree() {

    key_t keys[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    value_t values[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    const auto len = 9;

    HTree::tree_ptr_t tree = make_tree(keys, keys + len, values, values + len);
    
    std::cout << "Seach element: Path" << std::endl;
    
    for(auto i : keys) { // prints the results of each seach from the keys array
        std::cout << i << ": ";
        for(HTree::Direction dir : tree->path_to(i)){
            if(dir == HTree::Direction::LEFT){
                std::cout << 'L';
            }else{
                std::cout << 'R';
            }
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
                        // clean up
                        // the arrays from the top do not need to be cleaned up because they put onto the stack.
    return 0;
}

// recursively splits up the lists of keys and values among the children nodes so as to conveniently create a semi-balanced tree to run tests on.
HTree::tree_ptr_t make_tree(key_t * keys_start, key_t * keys_end, value_t * vals_start, value_t * vals_end)
{
    const auto keys_len = (keys_end - keys_start);
    const auto vals_len = (vals_end - vals_start);
    
    assert (keys_len == vals_len); // asserts that both arrays are of equal length

    if(keys_len <= 0){ // base case (no more elemets to make nodes from)
        return nullptr;
    }

    const auto half = (keys_len - 1) / 2; // where to split the lists

    // splits the lists of keys and values approximately evenly between the children nodes.
    HTree::tree_ptr_t left_node = make_tree(keys_start + 1, keys_start + 1 + half, vals_start + 1, vals_start + 1 + half);
    HTree::tree_ptr_t right_node = make_tree(keys_start + 1 + half, keys_end, vals_start + 1 + half, vals_end); 
    return std::shared_ptr<HTree>(new HTree(keys_start[0], vals_start[0], left_node, right_node));
} 
