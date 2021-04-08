
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

unsigned int* RandomPermutation(unsigned int n)
{
	unsigned int* arr = new unsigned int[n];

	for (unsigned int i = 0; i < n; i++)
		arr[i] = i;

	// Set different seed each time so we don't get the same result
	// each time we run this program.
	srand( (unsigned int) time(NULL));

	// Start from the last element and swap one-by-one.
	for (unsigned int i = n - 1; i > 0; i--) {
		unsigned int j = rand() % (i + 1);
		Swap(&arr[i], &arr[j]);
	}

	return arr;
}

void Swap(unsigned int* a, unsigned int* b)
{
	unsigned int tmp = *a;
	*a = *b;
	*b = tmp;
}

void PrintIntArray(unsigned int* arr, size_t n)
{
	for (size_t i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
}
