#include <iostream>
#include <time.h>
#include <chrono>
#include <vector>

using namespace std;

void FindPrimeNumber(int limit)
{
	vector<bool> prime(limit + 1, true);
	prime[0] = prime[1] = false; // 0 and 1 are not primes

	for (int p = 2; p * p <= limit; p++)
	{
		if (prime[p] == true)
		{
			for (int i = p * p; i <= limit; i += p)
			{
				prime[i] = false;
			}
		}
	}

	for (int p = 2; p <= limit; p++)
	{
		if (prime[p])
		{
			cout << p << " ";
		}
	}
}

int main()
{
	int limit = 1000000;
	chrono::time_point<chrono::system_clock> start;
	chrono::time_point<chrono::system_clock> end;
	chrono::duration<float> elapsed;

	start = chrono::system_clock::now();

	FindPrimeNumber(limit);

	end = chrono::system_clock::now();

	elapsed = end - start;

	cout << "Time to complete task: " << elapsed.count() << "seconds." << endl;

	return 0;

}
