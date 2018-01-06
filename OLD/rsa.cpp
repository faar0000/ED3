#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#include <math.h>


using namespace std;

class RSA{
    private:
//        char primos[5]={'2','3','5','7','11','\0'};//,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293}
        int p;
        int q;
        int n;
        int keye;
        int keyd;
        int fin;
        int var;
        string alfabeto="abcdefghijklmnopqrstuvwxyz ";

    public:
        RSA(){
           // primos=genprimos();
            p=11;//primos[rand()%4];
            q=13;//primos[rand()%4];
            n=p*q;
            fin=(p-1)*(q-1);
            keye=7;//gene();
            keyd=eu_ext(keye,fin);
        };
        RSA(int e,int a){
            keye=e;
            n=a;
        }

        char genprimos();
        int gene();
        int get_p(){return p;}
        int get_q(){return q;}
        int get_e(){return keye;}
        int get_n(){return n;}
        bool isPrime(int n, int k);
        bool miillerTest(int d, int n);
        int power(int x, unsigned int y, int p);
        int expmod(int base, int exp,int mod);
        int mod(int a, int n);
        int mcd(int x, int y);
        int resto_chino(int a,int b, int N);
        int conv(string a);
        int inversa(int a,int b );
        string codificar(string mensaje);
        string decodificar(string mensaje);
        string decodificar2(string mensaje);
        int eu_ext(int a,int b);
};

int RSA::mcd(int x, int y){
  return (!y) ? x : mcd(y,x%y);
}

int RSA::mod (int a,int n){
	int q, r;
	q = a/n;
	r = a - n*q;
	if (r<0){
		return r+n;
	}
}


int RSA::gene(){
    int num;
    while(num!=1){
        keye=rand()%n;
        num = mcd(keye,fin);
    }
    return keye;

}

char RSA::genprimos(){
    int m=0;
    int k = 4;  // numero de interaciones
    for (int n = 1; n < 100; n++)
       if (isPrime(n, k))
//            primos[m]=n;
            m++;
//    return primos;
//strcpy(primos,)
}

int RSA::expmod(int base, int exp,int mod) {
    int result=1,expmod;

    if(exp%2!=0)
        result=base%mod;
    exp=exp/2;

    while(exp>0){
        expmod=exp%2;
        base=(base*base)%mod;
        if(expmod!=0)
            result=(base*result)%mod;
        exp/=2;}
    return result;
}


int RSA::eu_ext(int a, int b){
    int base=b;
    int s1 = 1;
    int s2 = 0;
    int q = 0;
    int s = 0;
    int r = 0;
    while (b > 0){
        q = a / b;
        r = a - q * b;
        a = b;
        b = r;
        s = s1 - q * s2;
        s1 = s2;
        s2 = s;
    }
    s = s1;
    if(s<0){
        s=base+s;
    }
    return s;
}

bool RSA::isPrime(int n, int k)
{
    if (n <= 1 || n == 4)  return false;
    if (n <= 3) return true;
    int d = n - 1;
    while (d % 2 == 0){

        d /= 2;
    }
    for (int i = 0; i < k; i++){
         if (miillerTest(d, n) == false)
              return false;
    }
    return true;
}

bool RSA::miillerTest(int d, int n)
{
    int a = 2 + rand() % (n - 4);
    int x = power(a, d, n);
    if (x == 1  || x == n-1)
       return true;

    while (d != n-1)
    {
        x = (x * x) % n;
        d *= 2;

        if (x == 1)      return false;
        if (x == n-1)    return true;
    }

    return false;
}
int RSA::power(int x, unsigned int y, int p)
{
    int res = 1;      // Inicializar resultado
    x = x % p;   //Actualizar x si es mayor o igual que p
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}
int RSA::resto_chino(int a, int b, int N){
    int d=103;
    int dp,dq,p1,p2,q1,q2,b1,b2;
    dp=mod(d,(p-1));//HALLAR exponente dp
    b1=mod(a,p);//mod para recudir base dp
    b1=pow(b1,dp)+1;
    b1=mod(b1,p);//hallar el dp
    //asdasdsad
    dq=mod(d,(q-1));//hallar exp dq
    b2=mod(a,q);//reducir base
    b2=pow(b2,dq)+1;
    b2=mod(b2,q);//hallar dq
   //parte2
    p1=N/p;
    q1=eu_ext(p1,p);
    p2=N/q;
    q2=eu_ext(p2,q);
    int Do=mod((b1*p1*q1+b2*p2*q2),N);
    return Do;


}

string RSA::codificar(string mensaje){
    string temp;
    int letra;
    for (int i=0;i<mensaje.size();i++){
        letra=expmod(alfabeto.find(mensaje[i]),keye,n);
        temp+=letra;
    }
    return temp;
}

string RSA::decodificar(string mensaje){
    int letra;
    string temp;
    letra=resto_chino(mensaje[0],keyd,n);
    temp+=alfabeto[letra];
    return temp;

}

string RSA::decodificar2(string mensaje){
    string temp;
    int letra;
    for (int i=0;i<mensaje.size();i++){
        letra=expmod((mensaje[0]),keyd,n);
        temp+=alfabeto[letra];
    }
    return temp;
}

int main(){
RSA receptor;
RSA emisor(receptor.get_e(),receptor.get_n());
string mensaje,mensaje1;
cout<<"MENSAJE: ";
getline(cin,mensaje);

mensaje1=emisor.codificar(mensaje);
cout<<"CIFRADO: "<<mensaje1<<endl;

mensaje=receptor.decodificar2(mensaje1);
cout<<"DESCIFRADO: "<<mensaje<<endl;


return 0;
}














/*

void setkeys()
{
	int num = 11;
	srand(time(0));
	p = rand() % num + 5;
	while (!isPrime(p))
	{
		p = rand() % num + 5;
	}

	q = rand() % num + 5;
	while (!isPrime(q) || q == p)
	{
		q = rand() % num + 5;
	}
	n = p * q;
	tot = (p - 1) * (q - 1);
	e = 7;

}

int findE()
{
	int er = 2;
	while (LCD(er, tot) != 1) er++;
	return er;
}

*/
