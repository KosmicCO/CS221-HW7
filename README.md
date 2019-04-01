Extra Files Note -------------------

Because I wanted to separate the testing files for htree and hforest, I made a test_project file that runs either.


Building the Project----------------

Running `make` should work sufficiently. If you want to test htree instead of hforest, change `test` in test_project.cc from `1` to `0` and recompile.


HTree ------------------------------

HTree was contructed essentially the same as the previous assignment, except with private variables (and recursive function) and public interface.


HForest ----------------------------

I decided to go with the suggestion on the moodle to use a vector and apply make_heap on it with the custom comparator.
The tester for HForest also uses the make_tree function from test_htree.hh to work with actual trees.
