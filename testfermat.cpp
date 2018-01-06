#include <bits/stdc++.h>
using namespace std;


/* Función iterativa para calcular (a ^ n)% p en O (logy) */
int power(int a, unsigned int n, int p)
{
    int res = 1;// Initialize result
    //int conta = 0;
    a = a % p;  // Update 'a' if 'a' >= p

    while (n > 0)
    {
        // Si n es impar, multiplique 'a' con resultado
  //      conta+=1;
        if (n & 1)
            res = (res*a) % p;

        // n must be even now
        n = n>>1; // n = n/2
        a = (a*a) % p;
    }
//    cout<<"conta"<<conta;
    return res;
}

// Si n es primo, entonces siempre devuelve verdadero, Si n es
// compuesto que devuelve false con alta probabilidad
// Mayor valor de k aumenta probabilidad de corrección
// resultado.
bool isPrime(unsigned int n, int k)
{
   // Corner cases
   //int conta = 0;
   if (n <= 1 || n == 4)  return false;
   if (n <= 3) return true;

   // intenta k veces
   while (k>0)
   {
       // Elige un número aleatorio en [2..n-2]
        // Por encima de los esquineros asegúrese de que n> 4
     //   conta+=1;
       int a = 2 + rand()%(n-4);

       // Fermat's little theorem
       if (power(a, n-1, n) != 1)
          return false;

       k--;
    }
 //   cout<<"conta"<<conta;
    return true;
}

// Driver Program to test above function
int main()
{
    int k = 3;
    isPrime(997, k)?  cout << " true\n": cout << " false\n";
   // isPrime(15, k)?  cout << " true\n": cout << " false\n"<<cout<<conta;
    return 0;
}

