
#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;

//Funcion codifica
string codifica(int n, string cadena)
{
    string cadenaCod;
    int col = (double)cadena.length() / n;

    for (int i = 0; i < cadena.length(); i++) {
        cadenaCod += cadena[((n) * (i % col)) + (i / col)];
    }
    return cadenaCod;
}

//Funcion descodificar
string descodifica(int n, string cadena)
{
    string cadenaDecod;
    int col = (double)cadena.length() / n;

    for (int i = 0; i < cadena.length(); i++) {
        cadenaDecod += cadena[((col) * (i % (n))) + (i / n)];
    }
    return cadenaDecod;
}

//Programa principal
int main()
{
    string cadena, cadenaCod, cadenaDecod;
    int n;

    cout << "Introduce el mensaje a codificar" << endl;
    getline(cin, cadena);

    cout << "Introduce el numero de caras de la escitala" << endl;
    cin >> n;

    while (cadena.length() < (n * ceil((double)cadena.length() / n))) {
        cadena += " ";
    }

    cadenaCod = codifica(n, cadena);
    cout << cadenaCod << endl;
    cadenaDecod = descodifica(n, cadenaCod);
    cout << cadenaDecod << endl;

}
