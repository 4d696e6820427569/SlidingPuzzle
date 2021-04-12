#ifndef SLIDING_PUZZLE_MODEL_UTILS_H_
#define SLIDING_PUZZLE_MODEL_UTILS_H_

#include <vector>
#include "move.hpp"

/*
* Swap(a, b) --
*
* Utility function to swap 2 unsigned integers.
*/
void Swap(int* a, int* b);

/*
* RandomPermutation(n) --
* 
* Generate a random permutation of 0 to N-1 using the Fisher-Yates shuffle algorithm.
* Time complexity: O(n).
*/
int* RandomPermutation(int n);

void PrintIntArray(int* arr, size_t n);

void PrintMovesVector(std::vector<Move> &vm);

#endif // SLIDING_PUZZLE_MODEL_UTILS_H_