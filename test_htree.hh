#pragma once

#include "htree.hh"

using key_t = int;
using value_t = uint64_t;

int test_tree();

HTree::tree_ptr_t make_tree(key_t *, key_t *, value_t *, value_t *);
