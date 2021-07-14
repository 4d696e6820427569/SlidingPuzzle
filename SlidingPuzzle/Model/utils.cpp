#include <time.h>
#include <locale>

#include "utils.hpp"


void Swap(int* a, int* b)
{
	unsigned int tmp = *a;
	*a = *b;
	*b = tmp;
}

void RandomPermutation(const int& n, vector<int>& v)
{
	for (int i = 0; i < n; i++)
		v.emplace_back(i);

	srand((unsigned int)time(NULL));

	for (int i = n - 1; i > 0; i--) {
		int j = rand() % (i + 1);
		std::swap(v[i], v[j]);
	}
}

int* RandomPermutation(int n)
{
	int* arr = new int[n];

	for (int i = 0; i < n; i++)
		arr[i] = i;

	// Set different seed each time so we don't get the same result
	// each time we run this program.
	srand((unsigned int)time(NULL));

	// Start from the last element and swap one-by-one.
	for (int i = n - 1; i > 0; i--) {
		int j = rand() % (i + 1);
		Swap(&arr[i], &arr[j]);
	}

	return arr;
}

void PrintIntArray(int* arr, size_t n)
{
	for (size_t i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void DeleteIntArray(int** arr, size_t n)
{
	for (int i = 0; i < n; i++) {
		delete[] arr[i];
	}

	delete[] arr;
}

std::string& ltrim(std::string& str)
{
	auto it2 = std::find_if(str.begin(), str.end(), [](char ch) { return !std::isspace<char>(ch, std::locale::classic()); });
	str.erase(str.begin(), it2);
	return str;
}

std::string& rtrim(std::string& str)
{
	auto it1 = std::find_if(str.rbegin(), str.rend(), [](char ch) { return !std::isspace<char>(ch, std::locale::classic()); });
	str.erase(it1.base(), str.end());
	return str;
}

std::string trim_copy(std::string const& str)
{
	auto s = str;
	return ltrim(rtrim(s));
}
