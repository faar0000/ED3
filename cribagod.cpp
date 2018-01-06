#include <iostream>
#include <math.h>
#include <ctime>
#include <stdlib.h>
#include <vector>
#define ll long long
unsigned t0, t1;
using namespace std;
#define MAX_NUM 1000000000//limite para los primos
std::vector<char> primos;

const int L1D_CACHE_SIZE = 32768;
void primi(int64_t limit,int segment_size = L1D_CACHE_SIZE)
{
    int sqrt1 = (int) sqrt((double) limit);
    int64_t count = (limit < 2) ? 0 : 1;
    int64_t s = 2;
    int64_t n = 3;

    // vector used for sieving
    std::vector<char> sieve(segment_size);

    // generate small primes <= sqrt
    std::vector<char> is_prime(sqrt1 + 1, 1);
    for (int i = 2; i * i <= sqrt1; i++)
        if (is_prime[i])
            for (int j = i * i; j <= sqrt1; j += i)
                is_prime[j] = 0;

    std::vector<int> primes;
    std::vector<int> next;

    for (int64_t low = 0; low <= limit; low += segment_size)
    {
        std::fill(sieve.begin(), sieve.end(), 1);

        // current segment = interval [low, high]
        int64_t high = std::min(low + segment_size - 1, limit);

        // store small primes needed to cross off multiples
        for (; s * s <= high; s++)
        {
            if (is_prime[s])
            {
                primes.push_back((int) s);
                next.push_back((int)(s * s - low));
            }
        }
        // sieve the current segment
        for (std::size_t i = 1; i < primes.size(); i++)
        {
            int j = next[i];
            for (int k = primes[i] * 2; j < segment_size; j += k)
                sieve[j] = 0;
            next[i] = j - segment_size;
        }

        for (; n <= high; n += 2)
            if (sieve[n - low]) // n is a prime
                count++;
    }

    std::cout << count << " primes found." << std::endl;
}


/*void print()
{
    ll c = 0;
    for (int i = 0; i < MAX_NUM; i++)
    {
        if (sieve[i] == 1)//si es primo
        {
            c++;          //actualizo el valor del contador
            cout << c << "primo  : " << i << endl;//imprimo los primos
        }
    }
}*/

int main()
{
    t0=clock();
    primi( (int64_t)MAX_NUM);
    //erasto();
   // print();
    //sieve();
    t1 = clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Execution Time: " << time << endl;
    return 0;
}
