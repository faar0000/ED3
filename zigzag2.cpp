#include <bits/stdc++.h>
using namespace std;


string encripta(string text, int key)
{
    // CREAR MATRIZ
    // key = rows , length(text) = columns
    char rail[key][(text.length())];

    // llenando la matriz del carril para distinguir
    //espacios llenos de espacios en blanco
    for (int i=0; i < key; i++)
        for (int j = 0; j < text.length(); j++)
            rail[i][j] = '\n';

    // para encontrar la direccionw
    bool dir_down = false;
    int row = 0, col = 0;

    for (int i=0; i < text.length(); i++)
    {
        // verifique la dirección del flujo
        // invertir la dirección si acabamos de
        // llenar el riel superior o inferior
        if (row == 0 || row == key-1)
            dir_down = !dir_down;

        // llenar el alfabeto
        rail[row][col++] = text[i];

        //busque la siguiente fila usando el indicador de dirección
        dir_down?row++ : row--;
    }
    //construir el cifrado usando la matriz riel
    string result;
    for (int i=0; i < key; i++)
        for (int j=0; j < text.length(); j++)
            if (rail[i][j]!='\n')
                result.push_back(rail[i][j]);

    return result;
}

//descifrado
string desencripta(string cipher, int key)
{
    //crea la matriz para el cifrado del texto plano
    // key = filas , length(text) = columnas
    char rail[key][cipher.length()];
    //llenando la matriz riel
    for (int i=0; i < key; i++)
        for (int j=0; j < cipher.length(); j++)
            rail[i][j] = '\n';

    // para encontrar la direccion
    bool dir_down;

    int row = 0, col = 0;
    //marcar los lugares con "*"

    for (int i=0; i < cipher.length(); i++)
    {
        // revisar la direccion
        if (row == 0)
            dir_down = true;
        if (row == key-1)
            dir_down = false;

        // colocar el marcador
        rail[row][col++] = '*';

        // busque la siguiente fila usando el indicador de dirección
        dir_down?row++ : row--;
    }

    // ahora podemos construir el relleno de la matriz de carril
    int index = 0;
    for (int i=0; i<key; i++)
        for (int j=0; j<cipher.length(); j++)
            if (rail[i][j] == '*' && index<cipher.length())
                rail[i][j] = cipher[index++];


    string result;

    row = 0, col = 0;
    for (int i=0; i< cipher.length(); i++)
    {
        // verificar la direccion
        if (row == 0)
            dir_down = true;
        if (row == key-1)
            dir_down = false;

        // poner el marcador
        if (rail[row][col] != '*')
            result.push_back(rail[row][col++]);

        // busque la siguiente fila usando el indicador de dirección
        dir_down?row++: row--;
    }
    return result;
}

//driver program to check the above functions
int main()
{
    cout << encripta("holacomo ", 2) << endl;
    cout << encripta("que estoy haciendo", 3) << endl;

    cout << desencripta("hmooolca",4) << endl;
    cout << desencripta("atc toctaka ne",2) << endl;


    return 0;
}
