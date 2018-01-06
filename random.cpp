
#include <stdlib.h>
#include <time.h>
#include<iostream>
using namespace std;

int main()
{
    int num, c;
    srand(time(NULL));

    for(c = 1; c <= 10; c++)
    {
        num = 100000000000 + rand() % (100000000000000000000 - 1);
        cout << num<< " ";
    }

    return 0;
}
