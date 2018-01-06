#include <bits/stdc++.h>
using namespace std;

int CribaDeAtkin(int limit)
{
    // 2 y 3 son conocidos como primos
   // int contador=0;
    if (limit > 2)  cout << 2 << " ";
    if (limit > 3)  cout << 3 << " ";

    // Inicializar la matriz de tamiz con valores falsos
    bool criba[limit];
    for (int i=0; i<limit; i++)
        criba[i] = false;

    /* Marcar criba [n] es true si se cumple uno de los siguientes:
      A) n = (4 * x * x) + (y * y) tiene un número impar de soluciones, es decir, existen
         Número impar de pares distintos (x, y) que satisfacen la ecuación y
         N = 12 = 1 o n = 12 = 5.
      B) n = (3 * x * x) + (y * y) tiene un número impar de soluciones yn% 12 = 7
      C) n = (3 * x * x) - (y * y) tiene número impar de soluciones, x> y y n% 12 = 11 */
    for (int x = 1; x*x < limit; x++)
    {
        for (int y = 1; y*y < limit; y++)
        {
            // Parte principal del tamiz de Atkin
            int n = (4*x*x)+(y*y);
            if (n <= limit && (n % 12 == 1 || n % 12 == 5))
                criba[n] ^= true;

            n = (3*x*x)+(y*y);
            if (n <= limit && n % 12 == 7)
                criba[n] ^= true;

            n = (3*x*x)-(y*y);
            if (x > y && n <= limit && n % 12 == 11)
                criba[n] ^= true;
        }
    }

    // Marcar todos los múltiplos de cuadrados como no primos
    for (int r = 5; r*r < limit; r++)
    {
        if (criba[r])
        {
            for (int i = r*r; i < limit; i += r*r)
                criba[i] = false;
         }
    }

    // Imprimir primos usando criba []
    for (int a = 5; a < limit; a++){
        if (criba[a])
           cout << a << " ";
    }
}

int main(void)
{
    int limit = 1000000;
    CribaDeAtkin(limit);
    return 0;
}

