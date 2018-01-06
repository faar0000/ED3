#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> criba_eratostenes(int m)
{
    vector<int> criba;
    int min_=((pow(2,m))/2);
    m=pow(2,m);

    int current_primo;  // numero primo que iremos tomando del vector

    // vector con numeros desde 2 hasta n
    for (int i = min_; i <= m; i++)
        criba.push_back(i);

    if (min_== 2 ||min_== 3)
        return criba;

    // iterador para el vector criba
    vector<int>::iterator it = criba.begin();

    current_primo = *it;  // El primer primo es el 2

    do
    {
        vector<int>::iterator it2 = it + 1;

        for(; it2 <= criba.end(); it2++)
            if(*it2 % current_primo == 0)
                criba.erase(it2);

        it++;
        current_primo = *it;

    } while (pow(current_primo, 2) < min_);

    return criba;
}

int main()
{
    criba_eratostenes(5);
    return 0;
}
