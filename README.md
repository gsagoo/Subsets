# Subsets
C++ Code to calculate the subsets of a Parent set with elements 1 to n.
subsets_recursive.cpp (uses a recursive algorithm)
subsets_iterative.cpp (uses an iterative algorithm)

You can compile each source file using the commands below 

  ~~~
  g++ subsets_iterative.cpp -o subsets_ix -lm -O
  
  g++ subsets_recursive.cpp -o subsets_rx -lm -O
  ~~~
 or you could use the make file to compile the files with the commands 
 
  ~~~
  make iterative
  make recursive
  ~~~
The executibles can then be run using the commands 
  ```
  ./subsets_ix
  ./subsets_rx
  ```
 
