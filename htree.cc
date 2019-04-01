#include "htree.hh"
#include <assert.h>

HTree::HTree(int key, uint64_t value, HTree::tree_ptr_t left, HTree::tree_ptr_t right)
{
    key_ = key;         // standard constructor
    value_ = value;
    left_ = left;
    right_ = right;
}

int HTree::get_key() const
{
    return key_;
}

uint64_t HTree::get_value() const
{
    return value_;
}

HTree::tree_ptr_t HTree::get_child(Direction dir) const
{
    if(dir == Direction::LEFT){ // moves through the tree
        return left_;
    }
    return right_;
}

HTree::path_t HTree::path_to(int key) const
{
    path_t * result = HTree::recur_path_to(key);    // gets the path to the key
    assert(result);                                 // checks if it exist
    path_t ret = * result;                          // dereferences the path to be copied over
    delete result;
    return ret;
}

HTree::path_t * HTree::recur_path_to(int key) const
{
    if(key_ == key){                // if found return an empty path
        return new HTree::path_t();
    }

    if(left_){                                                      // if there is a left
        HTree::path_t * left_result = left_->recur_path_to(key);    // search it
        if(left_result){                                            // if found
            left_result->push_front(Direction::LEFT);               // add LEFT to the path
            return left_result;
        }
    }

    if(right_){                                                     // similarly to search left
        HTree::path_t * right_result = right_->recur_path_to(key);
        if(right_result){
            right_result->push_front(Direction::RIGHT);
            return right_result;
        }
    }

    return nullptr;             // return nullptr if not found
}














