#pragma once

#include <memory>
#include "htree.hh"
#include <vector>
#include <algorithm>


class HForest {
  private:
    std::vector<HTree::tree_ptr_t> * trees; // stores trees

  public:
    HForest();

    ~HForest();

    // required interface below

    int size() const;

    void add_tree(HTree::tree_ptr_t tree);

    HTree::tree_ptr_t pop_tree();
};

// interface for comparing trees

bool compare_trees(HTree::tree_ptr_t, HTree::tree_ptr_t);
