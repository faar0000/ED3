#include <bits/stdc++.h>
using namespace std;
// Función de utilidad para hacer exponenciación modular.
// Devuelve (x ^ y)% p
int power(int x, unsigned int y, int p)
{
    //int conta=0;
    int res = 1;      // Inicializar resultado
    x = x % p;   //Actualizar x si es mayor o igual que p
    while (y > 0)
    {
        // Si y es impar, multiplique x con resultado
   //     conta+=1;
        if (y & 1)
            res = (res*x) % p;

       // debe estar incluso ahora
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
 //   cout<<"cont"<<conta<<endl;
    return res;
}

// Esta función se llama para todos los ensayos k. Vuelve
// false si n es compuesto y devuelve false si n es
// probablemente prime.
// d es un número impar tal que d * 2 <sup> r </ sup> = n-1
// para algunos r> = 1
bool miillerTest(int d, int n)
{
    // Elige un número aleatorio en [2..n-2]
     // Los esquineros aseguran que n> 4
  //   int conta=0;
    int a = 2 + rand() % (n - 4);

    //  a^d % n
    int x = power(a, d, n);

    if (x == 1  || x == n-1)
       return true;

    // Mantenga cuadratura x mientras que uno de los siguientes no
     // ocurrir
     // (i) d no alcanza n-1
     // (ii) (x ^ 2)% n no es 1
     // (iii) (x ^ 2)% n no es n-1
    while (d != n-1)
    {
      //  conta+=1;
        x = (x * x) % n;
        d *= 2;

        if (x == 1)      return false;
        if (x == n-1)    return true;
    }
    //cout<<"cont"<<conta<<endl;
    // Compuesto de retorno
    return false;
}

// Devuelve false si n es compuesto y devuelve true si n
// es probablemente primo. K es un parámetro de entrada que determina
// nivel de precisión. El valor más alto de k indica una mayor precisión.
bool isPrime(int n, int k)
{
   //CASOS
  // int conta=0;
    if (n <= 1 || n == 4)  return false;
    if (n <= 3) return true;

  // Hallar r tal que n = 2 ^ d * r + 1 para algunos r> = 1
    int d = n - 1;
    while (d % 2 == 0){
      //  conta+=1;
        d /= 2;
    }
// Iterado dado nuemo de 'k' veces
    for (int i = 0; i < k; i++){
    //    conta+=1;
         if (miillerTest(d, n) == false)
              return false;
    }
  //  cout<<"cont"<<conta<<endl;
    return true;
}


int main()
{
    int k = 4;  // numero de interaciones
    cout << "Todos los primos menores que 100: \n";
    for (int n = 1; n < 1000; n++)
       if (isPrime(n, k))
          cout<<n<<" ";
//    cout<<"N"<<isPrime(200,4);

    return 0;
}

