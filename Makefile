CXX = g++
CCFLAGS = -g -Wall -Wextra -pedantic -Werror -std=c++17

%.o: %.cc
	$(CXX) $(CCFLAGS) -c $<

test_project: test_project.o test_hforest.o test_htree.o htree.o hforest.o
	$(CXX) -o test_project test_project.o test_hforest.o test_htree.o htree.o hforest.o

all: test_project

clean:
	rm -f *.o
	touch test_project
	rm test_project
