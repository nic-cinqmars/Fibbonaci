#include <iostream>
#include <chrono>

int fib1(int);
int fib2(int);
int fib3(int);

int main()
{
	// fib2
	for (int n = 10; n <= 1000000; n *= 10)
	{
		std::cout << "Executing fib2 with n = " << n << " ... ";
		auto startTime = std::chrono::high_resolution_clock::now();

		int result = fib2(n);

		auto endTime = std::chrono::high_resolution_clock::now();

		std::chrono::duration<double> elapsedTime = endTime - startTime;

		std::cout << result << " - Took " << elapsedTime.count() << " seconds.\n";
	}

	// fib3
	std::cout << "\n";
	for (int n = 10; n <= 1000000; n *= 10)
	{
		std::cout << "Executing fib3 with n = " << n << " ... ";
		auto startTime = std::chrono::high_resolution_clock::now();

		int result = fib3(n);

		auto endTime = std::chrono::high_resolution_clock::now();

		std::chrono::duration<double> elapsedTime = endTime - startTime;

		std::cout << result << " - Took " << elapsedTime.count() << " seconds.\n";
	}

	// fib1, extremely slow...
	std::cout << "\n";
	for (int n = 10; n <= 1000000; n *= 10)
	{
		std::cout << "Executing fib1 with n = " << n << " ... ";
		auto startTime = std::chrono::high_resolution_clock::now();

		int result = fib1(n);

		auto endTime = std::chrono::high_resolution_clock::now();

		std::chrono::duration<double> elapsedTime = endTime - startTime;

		std::cout << result << " - Took " << elapsedTime.count() << " seconds.\n";
	}
}

int fib1(int n)
{
	if (n < 2)
		return n;
	return fib1(n - 1) + fib1(n - 2);
}

int fib2(int n)
{
	int i = 1;
	int j = 0;

	for (int k = 1; k <= n; k++)
	{
		j = j + i;
		i = j - i;
	}

	return j;
}

int fib3(int n)
{
	int i = 1;
	int j = 0;
	int k = 0;
	int h = 1;

	while (n > 0)
	{
		if (n % 2)
		{
			int t = j * h;
			j = i * h + j * k + t;
			i = i * k + t;
		}

		int t = h * h;
		h = 2 * k * h + t;
		k = k * k + t;
		n = n / 2;
	}

	return j;
}