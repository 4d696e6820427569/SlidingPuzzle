#ifndef SLIDING_PUZZLE_MODEL_UTILS_HPP_
#define SLIDING_PUZZLE_MODEL_UTILS_HPP_

#include <vector>
#include <string>

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

template <typename T>
void PrintVector(std::vector<T> v)
{
	typename std::vector<T>::iterator it;
	for (it = v.begin(); it != v.end(); ++it) {
		printf("%s\n", (**it).ToString().c_str());
	}
	printf("\n");
};

template <typename T>
void DeleteObjectsVector(std::vector<T*> v)
{
	typename std::vector<T*>::iterator it;
	for (it = v.begin(); it != v.end(); ++it) {
		delete* it;
	}
};

std::string& ltrim(std::string& str);

std::string& rtrim(std::string& str);

std::string trim_copy(std::string const& str);

void DeleteIntArray(int** arr, size_t n);
#endif // SLIDING_PUZZLE_MODEL_UTILS_HPP_