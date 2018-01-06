#include <iostream>
#include <stdlib.h>


using namespace std;

class afin{
    private:
        int keya;
        int keyb;
        int var;
        string alfabeto="abcdefghijklmnopqrstuvwxyz ";

    public:
        afin(){
           keya=gena();
           keyb=(rand()%alfabeto.length());
        };
        afin(int a,int b){
            keya=a;
            keyb=b;
            var=eu_ext(keya,alfabeto.size());

        }
        int gena();
        int get_keya(){return keya;}
        int get_keyb(){return keyb;}
        int mod(int a, int n);
        int mcd(int x, int y);
        string codificar(string mensaje);
        string decodificar(string mensaje);
        int eu_ext(int a,int b);
};

int afin::mod (int a,int n){
	int q, r;
	q = a/n;
	r = a - n*q;
	if (r<0){
		return r+n;
	}
}

int afin::mcd(int x, int y){
  return (!y) ? x : mcd(y,x%y);
}

int afin::gena(){
    int num;
    while(num!=1){
        keya=rand()%alfabeto.length();
        num = mcd(alfabeto.length(),keya);
    }
    return keya;
}

int afin::eu_ext(int a, int b){
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
    return s;
}


string afin::codificar(string mensaje){
    string temp;
    int letra;
    for (int i=0;i<mensaje.size();i++){
        letra=mod((alfabeto.find(mensaje[i])*keya),alfabeto.size());
        temp=temp+alfabeto[mod(letra+keyb,alfabeto.size())];
    }
    return temp;

}

string afin::decodificar(string mensaje){
    string temp;
    int letra;
    for(int i=0;i<mensaje.size();i++){
        letra=mod((alfabeto.find(mensaje[i])-keyb),alfabeto.size());
        temp=temp+alfabeto[mod(letra*var,alfabeto.size())];
    }
    return temp;
}


int main(){
afin emisor;
afin receptor(emisor.get_keya(),emisor.get_keyb());
string mensaje,mensaje1;
cout<<"MENSAJE: ";
getline(cin,mensaje);

mensaje1=emisor.codificar(mensaje);
cout<<"CIFRADO: "<<mensaje1<<endl;

mensaje=receptor.decodificar(mensaje1);
cout<<"DESCIFRADO: "<<mensaje<<endl;


return 0;
}
