#include <cassert>
#include <iostream>
#include <ranges>
#include <vector>

// https://github.com/notMONGCHAW/CPP-Problem-Solving/blob/main/Problems/2.%20Medium/1.%20removeOddNumbersinArray.cpp

// ? Create a function that takes an array of numbers and returns only the even values.
/* Sample Output:
noOdds([1, 2, 3, 4, 5, 6, 7, 8]) ➞ [2, 4, 6, 8]
noOdds([43, 65, 23, 89, 53, 9, 6]) ➞ [6]
noOdds([718, 991, 449, 644, 380, 440]) ➞ [718, 644, 380, 440]
*/
// * Return all even numbers in the order they were given.
// * All test cases contain valid numbers ranging from 1 to 3000.

#define USE_RANGES

#ifdef USE_RANGES

std::vector<int> noOdds(const std::vector<int>& numbers)
{
	auto evenView = numbers | std::views::filter([](int i) { return i % 2 == 0; });
	return std::vector<int>(evenView.begin(), evenView.end());
}

#else

std::vector<int> noOdds(const std::vector<int>& numbers)
{
	std::vector<int> evens;
	for (int number : numbers)
	{
		if (number % 2 == 0)
		{
			evens.push_back(number);
		}
	}
	return evens;
}

#endif

int main(int argc, char* argv[])
{
	assert(noOdds({ 1, 2, 3, 4, 5, 6, 7, 8 }) == std::vector<int>({ 2, 4, 6, 8 }));
	assert(noOdds({ 43, 65, 23, 89, 53, 9, 6 }) == std::vector<int>({ 6 }));
	assert(noOdds({ 718, 991, 449, 644, 380, 440 }) == std::vector<int>({ 718, 644, 380, 440 }));

	// Empty vector.
	assert(noOdds({}) == std::vector<int>());

	// All odd or even.
	assert(noOdds({ 1, 3, 5 }) == std::vector<int>());
	assert(noOdds({ 2, 4, 6 }) == std::vector<int>({ 2, 4, 6 }));

	// Single value.	
	assert(noOdds({ 7 }) == std::vector<int>());
	assert(noOdds({ 8 }) == std::vector<int>{ 8 });

	// Repeated values.
	assert(noOdds({ 2, 2, 3, 4, 4 }) == std::vector<int>({ 2, 2, 4, 4 }));

	return 0;
}
