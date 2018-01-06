#include <iostream>
#include <stdlib.h>

using namespace std;

class cripto{
  private:
    int clave;
  public:

    string alfabeto="abcdefghijklmnopqrstuvwxyz ";
    cripto(int clave1){
        clave=clave1;
    }
    cripto();
    string codifica(string mensaje);
    string decodifica(string mensaje);
    int geta(){return clave;}
    int mod(int a, int n);
    int mcd(int x, int y);
    void setclave(int clave1);
};

int cripto::mod (int a,int n){
	int q, r;
	q = a/n;
	r = a - n*q;
	if (r<0){
		return r+n;
	}
}

int cripto::mcd(int x, int y){
  return (!y) ? x : mcd(y,x%y);
}

string cripto::codifica(string mensaje){
    string temp;
    int letra;
    for (int i=0;i<mensaje.size();i++){
        letra=mod((alfabeto.find(mensaje[i])+clave),alfabeto.size());
        temp=temp+alfabeto[letra];
    }
    return temp;
}

string cripto::decodifica(string mensaje){
    string temp;
    int letra;
    for (int i=0;i<mensaje.size();i++){
        letra=mod((alfabeto.find(mensaje[i])-clave),alfabeto.size());
        temp=temp+alfabeto[letra];
    }
    return temp;
}


int main(){

    int n=10;
    cripto emisor(n);
    cripto receptor(emisor.geta());
    string mensaje,mensaje1;
    cout<<"MENSAJE: ";
    getline(cin,mensaje);

    mensaje1=emisor.codifica(mensaje);
    cout<<"CIFRADO: "<<mensaje1<<endl;

    mensaje=receptor.decodifica(mensaje1);
    cout<<"DESCIFRADO: "<<mensaje<<endl;

}
