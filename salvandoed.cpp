#include <iostream>
#include <ctime>
#include<math.h>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#define ZZ long long

using namespace std;
/*  expo modular */
ZZ randomize(){
    ZZ randnumber;
    int digits=time(0);
    for(int i=305; i>=1; i--)
    {
       ZZ power=pow(10,(i-1)/digits);

        if (power%2 != 0 && power != 1)     //elimina el "bug" (which comes from long long power is not a float))
            power++;

        randnumber += power << digits;
    }
    if(randnumber%2==0)
        randnumber--;
return randnumber;
}

ZZ modulo(ZZ base, ZZ exponent, ZZ mod){
    ZZ x = 1;
    ZZ y = base;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            x = (x * y) % mod;
        y = (y * y) % mod;
        exponent = exponent / 2;
    }
    return x % mod;
}
bool fermat(ZZ p,int iterations){
        if (p == 1)
        {
            return false;
        }
        for (int i = 0; i < iterations; i++)
        {
            ZZ a = rand() % (p - 1) + 1;
            if (modulo(a, p - 1, p) != 1)
            {
                return false;
            }
        }
        return true;
}
ZZ generar(){

    ZZ numero = randomize();
    while (fermat(numero,3)==false){
        numero+=2;
    }
    return numero;
}

int main(){

    //cout <<fermat(4211491,10)<< endl;
    //cout <<randomize()<< endl;
    cout <<generar()<<endl;
    return 0;
}
