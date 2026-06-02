# Sorting Algorithms and Data Structure Examples (C++)

This repository contains standalone C++ programs that demonstrate sorting and tree-based data structure logic.

## Files

- `radix_sort.cpp`  
  Integer radix sort using bucket vectors and digit-by-digit processing.

- `strings_radix_sort.cpp`  
  String radix sort (lexicographic style) using character-position buckets.

- `quicksort.cpp`  
  Work-in-progress quicksort draft with pivot selection scaffolding.

- `Redblacktree.cpp`  
  Red-Black Tree implementation with insert balancing, search, and level-order traversal output.

## Running

Each file currently includes its own `main()` function and can be compiled/executed independently.

Example:

```bash
g++ -std=c++17 radix_sort.cpp -o radix_sort
./radix_sort
```
