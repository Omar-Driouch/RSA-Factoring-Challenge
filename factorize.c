#include <stdio.h>

int isPrime(long long n)
{
	if (n <= 1)
		return 0;

	for (long long i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

int printPrimesUpToN(long long numb, long long prime)
{
	int found = 0;
	for (long long i = 2; i <= numb; i++)
	{
		if (isPrime(i))
		{
			if (i * prime == numb)
			{
				printf("%lld = %lld * %lld\n", numb, i, prime);
				found = 1;
				break;
			}
		}
	}
	return found;
}

void findPrimeFactors(long long number)
{
	int check = 0;
	for (long long i = 2; i <= number; ++i)
	{
		if (number % i == 0 && isPrime(i) && check == 0)
		{
			check =	printPrimesUpToN(number, i);
		}

	}
}