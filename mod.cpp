#include <iostream>
#include <stdio.h>

using namespace std;



int mcd(int m, int n)
{
    int r,q;
    //if(m<n)
       // swap(m,n);

    while(r!=0)
    {
        q=m/n;
        r=m-q*n;//funcion para el "modulo" m,n
        m=n;//reasigno las variablescout << c << "\n";
        n=r;
    }
    return m;/*m es el ultimo resto no nulo*/
}

int main()
{
    cout<<mcd(72,80);


    return 0;
}
