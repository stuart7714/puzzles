// https://open.kattis.com/problems/gcd

#include <cassert>
#include <format>

int Gcd(int a, int b)
{
	while (b != 0)
	{
		a = std::exchange(b, a % b);
	}

	return a;
}

void GcdCheck(int a, int b, int expectedResult)
{
	int gcd = Gcd(a, b);
	assert(gcd == expectedResult);
	printf(std::format("gcd({}, {}) = {}\n", a, b, gcd).c_str());
}

int main()
{
	// Check GCD.
	GcdCheck(750, 900, 150);

	// Check commutativity.
	GcdCheck(48, 180, 12);
	GcdCheck(180, 48, 12);

	// Check negative value.
	GcdCheck(-12, 18, 6);

	// Check zero.
	GcdCheck(16, 0, 16);

	// Check large value.
	GcdCheck(1000000000, 1500, 500);

	return 0;
}
