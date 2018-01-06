#include <iostream>
#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;

ZZ Dijkstra(ZZ m, ZZ n) {
            cout<<m<<"\t"<<n<<endl;
            if(m == n)
    				 return m;
  			else if (m > n)
    				 return Dijkstra(m-n, n);
            else
     				return Dijkstra(m, n-m);
}

int main()
{
   ZZ M,N;
   M = 468, N = 24;
   cout << Dijkstra(M, N);
   return 0;
}
