#include"isPrime.h"
_Bool isPrime(int n)
{
	int boolen = 0;
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			boolen = false;
			break;
		}
		if (i == n - 1)
		{
			boolen = true;
			break;
		}
	}
	return boolen;
}
