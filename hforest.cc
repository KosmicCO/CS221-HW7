#include "hforest.hh"
#include <vector>

HForest::HForest(){
    trees_ = new std::vector<HTree::tree_ptr_t>();
}

HForest::~HForest(){
    delete trees_;
}

int HForest::size() const {
    return trees_->size();       // wrapper for vector
}

void HForest::add_tree(HTree::tree_ptr_t tree){
    trees_->push_back(tree);     // wrapper for vector
}

bool compare_trees(HTree::tree_ptr_t t1, HTree::tree_ptr_t t2){
    return t1->get_value() > t2->get_value();   // in assending order
}

HTree::tree_ptr_t HForest::pop_tree(){
    std::make_heap(trees_->begin(), trees_->end(), compare_trees);    // makes the vector into a heap
    HTree::tree_ptr_t top = trees_->back();                          // gets greatest
    trees_->pop_back();
    return top;
}
