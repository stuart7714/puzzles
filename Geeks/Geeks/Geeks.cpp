#include <algorithm>
#include <array>
#include <charconv>
#include <format>
#include <iostream>
#include <numeric>

// https://www.geeksforgeeks.org/cpp/cpp-exercises/

namespace
{
	void Q1_PrintString()
	{
		std::cout << "Hello World" << std::endl;
	}

	void Q2_ReadAndPrintInteger()
	{
		int input;
		std::cout << "Enter any Number: ";
		std::cin >> input;
		if (!std::cin)
		{
			std::cout << "User did not enter integer." << std::endl;
			return;
		}
		std::cout << std::format("Entered Number : {}", input) << std::endl;
	}

	void Q3_PrintAscii(char input)
	{
		std::cout << std::format("Character = {}", input) << std::endl;
		std::cout << std::format("ASCII Value of '{}' = {}", input, static_cast<int>(input)) << std::endl;
	}

	void Q4_SwapIntegers(int a, int b, bool simplifySolution)
	{
		std::cout << std::format("a = {}, b = {}", a, b) << std::endl;
		if (simplifySolution)
		{
			std::swap(a, b);
		}
		else
		{
			int temp = a;
			a = b;
			b = temp;
		}
		std::cout << std::format("a = {}, b = {}", a, b) << std::endl;
	}

	void Q5_PrintSizes()
	{
		std::cout << std::format("size of int: {} bytes", sizeof(int)) << std::endl;
		std::cout << std::format("size of float : {} bytes", sizeof(float)) << std::endl;
		std::cout << std::format("size of double : {} bytes", sizeof(double)) << std::endl;
		std::cout << std::format("size of char : {} bytes", sizeof(char)) << std::endl;
	}

	void Q7_EvenOrOdd(int number)
	{
		std::cout << std::format("Number = {}", number) << std::endl;
		std::cout << std::format("{} is {} Number", number, number % 2 == 0 ? "Even" : "Odd") << std::endl;
	}

	void Q8_LargestAmongThree(int a, int b, int c, bool simplifySolution)
	{
		std::cout << std::format("a = {}, b = {} and c = {}", a, b, c) << std::endl;
		if (simplifySolution)
		{
			std::array<std::pair<int, char>, 3> numbers = { std::pair(a, 'a'), std::pair(b, 'b'), std::pair(c, 'c') };
			std::ranges::sort(numbers, std::greater{}, &std::pair<int, char>::first);
			if (numbers[0].first != numbers[1].first)
			{
				std::cout << std::format("{} is the largest.", numbers[0].second) << std::endl;
			}
			else
			{
				std::cout << "No value is the largest." << std::endl;
			}
		}
		else
		{
			if (a > b && a > c)
			{
				std::cout << "a is the largest." << std::endl;
			}
			else if (b > a && b > c)
			{
				std::cout << "b is the largest." << std::endl;
			}
			else if (c > a && c > b)
			{
				std::cout << "c is the largest." << std::endl;
			}
			else
			{
				std::cout << "No value is the largest." << std::endl;
			}
		}
	}

	void Q9_LeapYear(int year)
	{
		auto isLeapYear = [](int year)
		{
			if (year % 400 == 0)
			{
				return true;
			}
			else if (year % 100 == 0)
			{
				return false;
			}
			else if (year % 4 == 0)
			{
				return true;
			}
			else
			{
				return false;
			}
		};

		std::cout << std::format("{} {} a Leap Year", year, isLeapYear(year) ? "is" : "is not") << std::endl;
	}

	void Q10_Prime(int number)
	{
		auto isPrime = [](int number)
		{
			if (number < 2 == 0)
			{
				return false;
			}
			// i <= sqrt(number), becomes:
			// pow(i, 2) <= number, becomes:
			// i * i <= number, becomes:
			// i <= number / i
			for (int i = 2; i <= number / i; i++)
			{
				if (number % i == 0)
				{
					return false;
				}
			}
			return true;
		};

		std::cout << std::format("{} {} a prime number.", number, isPrime(number) ? "is" : "is not") << std::endl;
	}

	void Q11_Palindrome(long long number)
	{
		auto isPalindrome = [](long long number)
		{
			long long forwards = number;
			long long backwards = 0;
			while (forwards)
			{
				backwards += forwards % 10;
				forwards /= 10;
				if (forwards)
				{
					backwards *= 10;
				}
			}
			return number == backwards;
		};

		std::cout << std::format("{} {} a palindrome number.", number, isPalindrome(number) ? "is" : "is not") << std::endl;
	}

	void Q12_Calculator()
	{
		std::cout << "Enter the Number" << std::endl;
		int a;
		std::cin >> a;
		int b;
		std::cin >> b;
		std::cout << "Enter a for addition,\ns for substraction,\nm for multiplication,\nd for division." << std::endl;
		char op;
		std::cin >> op;
		op = std::tolower(op);
		int result = 0;
		switch (op)
		{
			case 'a':
			{
				result = a + b;
			}
			break;
			case 's':
			{
				result = a - b;
			}
			break;
			case 'm':
			{
				result = a * b;
			}
			break;
			case 'd':
			{
				if (b == 0)
				{
					std::cout << "Cannot divide by zero." << std::endl;
					return;
				}
				result = a / b;
			}
			break;
			default:
			{
				std::cout << "Operation must be 'a' (addition), 's' (subtraction), 'm' (multiplication), or 'd' (division)." << std::endl;
				return;
			}
		}
		std::cout << result << std::endl;
	}

	std::string ReverseRecursive(std::string& forward)
	{
		if (forward.length() == 1)
		{
			return forward;
		}
		else
		{
			std::string backwards;
			backwards.push_back(forward.back());
			forward.pop_back();
			backwards += ReverseRecursive(forward);
			return backwards;
		}
	}

	std::string Reverse(const std::string& input)
	{
		if (input.empty())
		{
			return input;
		}
		std::string forwards = input;
		return ReverseRecursive(forwards);
	}

	void Q13_Reverse(const std::string& input)
	{
		std::cout << Reverse(input) << std::endl;
	}

	int Fibonacci(int n)
	{
		if (n < 0)
		{
			throw std::invalid_argument(std::format("Cannot find Fibonacci value of negative number: {}.", n));
		}
		if (n == 0)
		{
			return 0;
		}
		else if (n == 1)
		{
			return 1;
		}
		return Fibonacci(n - 1) + Fibonacci(n - 2);
	}

	void Q14_Fibonacci(int n)
	{
		try
		{
			std::cout << Fibonacci(n) << std::endl;
		}
		catch (const std::invalid_argument& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	void Q16_ArraysEqual()
	{
		int arr1[] = { 5, 8, 3 };
		int arr2[] = { 5, 8, 11, 2 };

		if (std::size(arr1) != std::size(arr2))
		{
			std::cout << "arr1[] and arr2[] are not equal." << std::endl;
			return;
		}

		for (int idx = 0; idx < std::size(arr1); idx++)
		{
			if (arr1[idx] != arr2[idx])
			{
				std::cout << "arr1[] and arr2[] are not equal." << std::endl;
				return;
			}
		}

		std::cout << "arr1[] and arr2[] are equal." << std::endl;
	}

	void Q17_Average(bool simplifySolution)
	{
		std::array arr = { 10, 22, 45, 11 };

		int total = 0;
		if (simplifySolution)
		{
			total = std::accumulate(arr.begin(), arr.end(), 0);
		}
		else
		{
			for (int val : arr)
			{
				total += val;
			}
		}

		float avg = total / static_cast<float>(arr.size());
		std::cout << std::format("Average = {}", avg) << std::endl;
	}

	void Q18_MinAndMax(bool simplifySolution)
	{
		std::array arr = { 10, 12, 45, 48, 22, 18 };

		if (simplifySolution)
		{
			auto [min, max] = std::ranges::minmax(arr);
			std::cout << std::format("Maximum = {}\nMinimum = {}", max, min) << std::endl;
		}
		else
		{
			int min = INT_MAX;
			int max = INT_MIN;

			for (int val : arr)
			{
				min = std::min(val, min);
				max = std::max(val, max);
			}

			std::cout << std::format("Maximum = {}\nMinimum = {}", max, min) << std::endl;
		}
	}
}

int main(int argc, char* argv[])
{
	Q1_PrintString();
	Q2_ReadAndPrintInteger();
	Q3_PrintAscii('A');
	Q4_SwapIntegers(10, 250, false);
	Q4_SwapIntegers(10, 250, true);
	Q5_PrintSizes();
	Q7_EvenOrOdd(28);
	Q8_LargestAmongThree(10, 21, 4, false);
	Q8_LargestAmongThree(10, 21, 4, true);
	Q9_LeapYear(2020); // Leap year.
	Q9_LeapYear(1900); // Not leap year. 
	Q9_LeapYear(2000); // Leap year.
	Q10_Prime(29);
	Q10_Prime(28);
	Q11_Palindrome(1231);
	Q12_Calculator();
	Q13_Reverse("Quick brown fox");
	Q14_Fibonacci(12);
	Q16_ArraysEqual();
	Q17_Average(false);
	Q17_Average(true);
	Q18_MinAndMax(false);
	Q18_MinAndMax(true);
}
