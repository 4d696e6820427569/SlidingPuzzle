#ifndef SLIDING_PUZZLE_MODEL_UTILS_H_
#define SLIDING_PUZZLE_MODEL_UTILS_H_

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

#endif // SLIDING_PUZZLE_MODEL_UTILS_H_