#include "test_htree.hh"
#include "test_hforest.hh"

int main(){
    
    auto test = 1;  // test_hforest

    switch(test){
    case 0:
        return test_tree();
    case 1:
        return test_forest();
    }
    return 1;
}
