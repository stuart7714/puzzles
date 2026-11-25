#include <algorithm>
#include <array>
#include <charconv>
#include <format>
#include <iostream>
#include <numeric>
#include <ranges>
#include <vector>

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

	void Q19_SearchArray(int element, bool simplifySolution)
	{
		std::array arr = { 10, 11, 7, 8, 2, 9 };

		if (simplifySolution)
		{
			auto found = std::ranges::find(arr, element);
			if (found == arr.end())
			{
				std::cout << std::format("{} not found in the arr[]", element) << std::endl;
			}
			else
			{
				std::cout << std::format("{} found in the arr[] at index {}", element, std::distance(arr.begin(), found)) << std::endl;
			}
		}
		else
		{
			for (int idx = 0; idx < arr.size(); idx++)
			{
				if (arr[idx] == element)
				{
					std::cout << std::format("{} found in the arr[] at index {}", element, idx) << std::endl;
					return;
				}
			}

			std::cout << std::format("{} not found in the arr[]", element) << std::endl;
		}
	}

	void Q20_RotateArray(int k, bool simplifySolution)
	{
		std::array arr = { 10, 11, 7, 33, 5, 1 };

		if (simplifySolution)
		{
			std::rotate(arr.begin(), arr.begin() + k % arr.size(), arr.end());
		}
		else
		{
			for (int rot = 0; rot < k; rot++)
			{
				int last = arr.back();
				for (size_t i = arr.size() - 1; i > 0; i--)
				{
					arr[i] = arr[i - 1];
				}
				arr[0] = last;
			}
		}

		std::string output = std::format("{{{}", arr[0]);
		for (int idx = 1; idx < arr.size(); idx++)
		{
			output += std::format(", {}", arr[idx]);
		}
		output += "}";

		std::cout << std::format("Array after rotation: {}", output) << std::endl;
	}

	void Q21_MatrixSumOfDiagonals()
	{
		std::array<std::array<int, 3>, 3> matrix = { {
			{ 1, 2, 3 },
			{ 4, 5, 6 },
			{ 7, 8, 9 }
		} };

		int principal = 0;
		for (int i = 0; i < matrix.size(); i++)
		{
			principal += matrix[i][i];
		}
		std::cout << std::format("Principal Diagonal = {}", principal) << std::endl;

		int secondary = 0;
		for (int i = 0; i < matrix.size(); i++)
		{
			secondary += matrix[matrix.size() - i - 1][i];
		}
		std::cout << std::format("Secondary Diagonal = {}", secondary) << std::endl;
	}

	void Q22_RotateMatrix(int k)
	{
		std::array<std::array<int, 3>, 3> matrix = { {
			{ 1, 2, 3 },
			{ 4, 5, 6 },
			{ 7, 8, 9 }
		} };

		auto nonrotated = matrix;
		auto rotated = matrix;

		for (size_t rot = 0; rot < k; rot++)
		{
			for (size_t row = 0; row < nonrotated.size(); row++)
			{
				size_t rowSize = nonrotated[row].size();
				for (size_t col = 0; col < rowSize; col++)
				{
					rotated[col][rowSize - row - 1] = nonrotated[row][col];
				}
			}
			nonrotated = rotated;
		}

		for (size_t row = 0; row < rotated.size(); row++)
		{
			size_t rowSize = rotated[row].size();
			for (size_t col = 0; col < rowSize; col++)
			{
				std::cout << rotated[row][col] << " ";
			}
			std::cout << std::endl;
		}
	}

	void Q23_StringLen(const std::string& input, bool simplifySolution)
	{
		size_t len = 0;
		if (simplifySolution)
		{
			len = std::ranges::count_if(input, [](int) { return true; });
		}
		else
		{
			for (char c : input)
			{
				len++;
			}
		}
		std::cout << std::format("Length of str = {}", len) << std::endl;
	}

	void Q24_StringCompare(const std::string& str1, const std::string& str2, bool simplifySolution)
	{
		auto stringCompare = [](const std::string& str1, const std::string& str2, bool simplifySolution) {
			if (simplifySolution)
			{
				return std::ranges::equal(str1, str2, [](char c1, char c2) {return c1 == c2;});
			}
			else
			{
				if (str1.length() != str2.length())
				{
					return false;
				}
				for (auto c1 = str1.begin(), c2 = str2.begin(); c1 != str1.end(); ++c1, ++c2)
				{
					if (*c1 != *c2)
					{
						return false;
					}
				}
				return true;
			}
		};

		std::cout << std::format("str1 and str2 {} equal.", stringCompare(str1, str2, simplifySolution) ? "are" : "are not") << std::endl;
	}

	void Q25_StringPalindrome(const std::string& input)
	{
		auto isPalindrome = [](const std::string& input) {
			if (input.empty())
			{
				return true;
			}
			for (auto begin = input.begin(), end = input.end() - 1; begin < end; ++begin, --end)
			{
				if (*begin != *end)
				{
					return false;
				}
			}
			return true;
		};
		std::cout << std::format("str {} a palindrome string.", isPalindrome(input) ? "is" : "is not") << std::endl;
	}

	void Q26_AddBinaryStrings(const std::string& a, const std::string& b)
	{
		auto binToInt = [](char c)
		{
			switch (c)
			{
				case '0':
				{
					return 0;
				}
				break;
				case '1':
				{
					return 1;
				}
				break;
				default:
				{
					throw std::invalid_argument(std::format("Character is not '0' or '1': {}.", c));
				}
				break;
			}
		};

		try
		{
			std::string sum;
			size_t maxLen = std::max(a.length(), b.length()) + 1;
			sum.reserve(maxLen);

			int aIdx = static_cast<int>(a.length()) - 1;
			int bIdx = static_cast<int>(b.length()) - 1;
			int carry = 0;

			while (aIdx >= 0 || bIdx >= 0 || carry != 0)
			{
				int aVal = aIdx >= 0 ? binToInt(a[aIdx]) : 0;
				int bVal = bIdx >= 0 ? binToInt(b[bIdx]) : 0;

				int total = aVal + bVal + carry;
				switch (total)
				{
					case 0:
					{
						sum.insert(0, "0");
						carry = 0;
					}
					break;
					case 1:
					{
						sum.insert(0, "1");
						carry = 0;
					}
					break;
					case 2:
					{
						sum.insert(0, "0");
						carry = 1;
					}
					break;
					case 3:
					{
						sum.insert(0, "1");
						carry = 1;
					}
					break;
					default:
					{
						throw std::runtime_error("Binary overflow");
					}
				}

				aIdx--;
				bIdx--;
			}

			std::cout << sum << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	void Q27_StringToInt(const std::string& input)
	{
		auto digitToInt = [](char c)
		{
			switch (c)
			{
			case '0': return 0;
			case '1': return 1;
			case '2': return 2;
			case '3': return 3;
			case '4': return 4;
			case '5': return 5;
			case '6': return 6;
			case '7': return 7;
			case '8': return 8;
			case '9': return 9;
			default:
			{
				throw std::invalid_argument(std::format("Character is not a digit: {}.", c));
			}
			break;
			}
		};

		auto stringToInt = [&digitToInt](const std::string& input) {
			if (input.length() == 0)
			{
				return 0;
			}
			int value = 0;
			for (auto it = input.cbegin(); it != input.cend(); ++it)
			{
				value *= 10;
				value += digitToInt(*it);

			}
			return value;
		};

		std::cout << std::format("Number = {}", stringToInt(input)) << std::endl;
	}

	void Q28_Substrings(const std::string& input, char delimiter)
	{
		std::vector<std::string> substrings;
		std::string::size_type startIdx = 0;
		for (std::string::size_type currentIdx = 0; currentIdx < input.size(); currentIdx++)
		{
			if (input[currentIdx] == delimiter)
			{
				substrings.emplace_back(input.substr(startIdx, currentIdx - startIdx));
				startIdx = currentIdx + 1;
			}
		}
		substrings.emplace_back(input.substr(startIdx));

		std::cout << "Output:\n";
		for (const std::string& substring : substrings)
		{
			std::cout << substring << "\n";
		}
	}

	void Q29_PrintPyramid(int numRows)
	{
		for (int row = 1; row <= numRows; row++)
		{
			std::string line(numRows - row, ' ');
			line += "*";
			for (int star = 1; star < row; star++)
			{
				line += " *";
			}
			std::cout << line << "\n";
		}
	}

	void Q31_PascalsTriangle(int numRows)
	{
		auto fac = [](int n)
		{
			int result = 1;
			for (int f = 2; f <= n; f++)
			{
				result *= f;
			}
			return result;
		};

		for (int n = 0; n < numRows; n++)
		{
			for (int k = 0; k <= n; k++)
			{
				std::cout << fac(n) / (fac(k) * fac(n - k)) << " ";
			}
			std::cout << "\n";
		}
	}

	void Q32_BinaryToDecimal(const std::string& input)
	{
		auto binToInt = [](char c)
		{
			switch (c)
			{
				case '0': return 0;
				case '1': return 1;
				default:
				{
					throw std::invalid_argument(std::format("Character is not '0' or '1': {}.", c));
				}
				break;
			}
		};

		int result = 0;
		for (char c : input)
		{
			result *= 2;
			result += binToInt(c);
		}

		std::cout << result << std::endl;
	}

	void Q33_DecimalToOctal(int value)
	{
		std::string result;
		while (value)
		{
			int oct = value % 8;
			result.push_back('0' + oct);
			value /= 8;
		}
		std::ranges::reverse(result);
		std::cout << result;
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
	Q19_SearchArray(8, false);
	Q19_SearchArray(5, false);
	Q19_SearchArray(8, true);
	Q19_SearchArray(5, true);
	Q20_RotateArray(3, false);
	Q20_RotateArray(3, true);
	Q21_MatrixSumOfDiagonals();
	Q22_RotateMatrix(2);
	Q23_StringLen("GeeksforGeeks", false);
	Q23_StringLen("GeeksforGeeks", true);
	Q24_StringCompare("Geeks", "geeks", false);
	Q24_StringCompare("Geeks", "geeks", true);
	Q25_StringPalindrome("naman");
	Q26_AddBinaryStrings("11", "1");
	Q27_StringToInt("69420");
	Q28_Substrings("Welcome Geeks to the GeeksforGeeks portal.", ' ');
	Q29_PrintPyramid(5);
	Q31_PascalsTriangle(5);
	Q32_BinaryToDecimal("101011");
	Q33_DecimalToOctal(100);
}
