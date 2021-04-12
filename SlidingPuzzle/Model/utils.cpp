
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

int* RandomPermutation(int n)
{
	int* arr = new int[n];

	for (int i = 0; i < n; i++)
		arr[i] = i;

	// Set different seed each time so we don't get the same result
	// each time we run this program.
	srand( (unsigned int) time(NULL));

	// Start from the last element and swap one-by-one.
	for (int i = n - 1; i > 0; i--) {
		int j = rand() % (i + 1);
		Swap(&arr[i], &arr[j]);
	}

	return arr;
}

void Swap(int* a, int* b)
{
	unsigned int tmp = *a;
	*a = *b;
	*b = tmp;
}

void PrintIntArray(int* arr, size_t n)
{
	for (size_t i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void PrintMovesVector(std::vector<Move> &vm)
{
	for (std::vector<Move>::iterator it = vm.begin(); it != vm.end(); it++) {
		printf("%s", (*it).ToString().c_str());
	}

	printf("\n");
}
