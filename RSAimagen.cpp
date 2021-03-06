#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#include <math.h>
#include <NTL/ZZ.h>
#include <cstdio>
#include "CImg.h"
//#include <ma.h>


using namespace std;
using namespace NTL;
using namespace cimg_library;

class RSA{
    private:
        ZZ p;
        ZZ q;
        ZZ n;
        ZZ keye;
        ZZ keyd;
        ZZ fin;
        ZZ var;
        string alfabeto="0123456789.abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ (),-_";

    public:
        RSA(int bits){
            vector<int>primos;
            criba(bits,primos);
            p=primos[rand()%primos.size()];
            q=primos[rand()%primos.size()];
            n=p*q;
            fin=(p-1)*(q-1);
            keye=gene();
            keyd=eu_ext(fin,keye);

        };
     /*   RSA(){
            p=17;
            q=11;
            n=p*q;
            fin=(p-1)*(q-1);
            keye=7;
            //keye=gene();
            keyd=eu_ext(fin,keye);
        };*/
        RSA(ZZ e,ZZ a){
            keye=e;
            n=a;
        }

        ZZ gene();
        ZZ get_p(){return p;}
        ZZ get_q(){return q;}
        ZZ get_e(){return keye;}
        ZZ get_n(){return n;}
        ZZ eu_ext(ZZ a,ZZ b);
        ZZ expmod(ZZ base, ZZ exp,ZZ mod);
        ZZ modulo(ZZ a, ZZ b);
        int modulo1(int a,int b);
        ZZ mcd(ZZ a, ZZ b);
        ZZ exp(ZZ base, ZZ exponente);
        ZZ resto_chino(ZZ a,ZZ b, ZZ N);
        ZZ STRa_ZZ(string str);
        string imagen();
        vector<int> criba(int  max_,vector<int> &primo);
        string ZZa_STR(ZZ a);
        string INTa_STR(int a);
        string add_0(ZZ num, int K);
        string codificar(string mensaje);
        string decodificar(string mensaje);
        string codiimagen(string mensaje);
        void Print(string men);
        void Print1(string men);
        int rgb(string im,int &in);
        int rgb1(string im,int &in);
        CImg<unsigned char> Binarizar(char const *nombre,string &rgb);
        CImg<unsigned int> armar(string im, int &ancho, int &alto);
        CImg<unsigned int> desarmar(string im, int &ancho, int &alto);

};

//https://stackoverflow.com/questions/3291923/how-to-get-rgb-value-by-cimg
CImg<unsigned char> RSA::Binarizar(char const *nombre,string &rgb){
    CImg<unsigned char> imagen(nombre);
    unsigned char r,g,b;
    ZZ r1,g1,b1;
    CImg<int> imagenBW(imagen.width(),imagen.height(),1,1);
    int c=0;
    for(int x=0;x<imagenBW.width();x++){
        for(int y=0;y<imagenBW.height();y++){
                r=imagen(x,y,0,0);
                r1=conv<ZZ>(int(r));

                g=imagen(x,y,0,1);
                g1=conv<ZZ>(int(g));

                b=imagen(x,y,0,2);
                b1=conv<ZZ>(int(b));

                //rgb=rgb+ZZa_STR(r1)+ZZa_STR(g1),ZZa_STR(b1);

                rgb=rgb+add_0(r1,3)+add_0(g1,3),add_0(b1,3);

        }
    }
   /* for(int j=0;j<rgb.size();j++){
        cout<<rgb[j];
    }*/

    rgb=codificar(rgb);

    return imagenBW;
}


int RSA::rgb1(string im,int &in){
    string temp=im.substr(in,3);
    int p=atoi(temp.c_str());
    in=in+3;
    return p;
}

int RSA::rgb(string im,int &in){
    string temp=im.substr(in,3);
    int p=atoi(temp.c_str());
    if(p>255){
        p=atoi((im.substr(in,2)).c_str());
        in=in+2;
        return p;
    }
    in=in+3;
    return p;
}
/*int RSA::rgb(string im,int &in){
    string temp=im.substr(in,2);
    int p=atoi(temp.c_str());
    p=atoi((im.substr(in,2)).c_str());
    in=in+2;
    return p;
}
*/

CImg<unsigned int> RSA::armar(string im, int &ancho, int &alto){
    CImg<unsigned int> nueva(ancho,alto,1,3,0);
    int in,temp;
    in=0;
    for(int x=0;x<ancho;x++){
        for(int y=0;y<alto;y++){
            for(int z=0;z<3;z++){
                temp=rgb(im,in);
                nueva(x,y,z)=temp;
            }
        }
    }
    return nueva;
}

CImg<unsigned int> RSA::desarmar(string im, int &ancho, int &alto){
    CImg<unsigned int> nueva(ancho,alto,1,3,0);
    int in,temp;
    in=0;
    for(int x=0;x<ancho;x++){
        for(int y=0;y<alto;y++){
            for(int z=0;z<3;z++){
                temp=rgb1(im,in);
                nueva(x,y,z)=temp;
            }
        }
    }
    return nueva;
}



ZZ RSA::mcd(ZZ a,ZZ b){
    if (a==0){
        return b;
    }
    else{
        ZZ r;
        while(b>0){
           r=modulo(a,b);
           a=b;
           b=r;
        }
    }
    return a;
}

ZZ RSA::exp(ZZ base,ZZ exponente){
    ZZ resultado;resultado=1;
    while(exponente!=0){
    if(exponente-((exponente>>1)<<1)==1){
        resultado=base*resultado;
    }
    base=base*base;
    exponente=exponente>>1;
    }
    return resultado;

}

ZZ RSA::modulo(ZZ a, ZZ b){
    ZZ r;
    r=a-((a/b)*b);
    if(r>=0){
        return r;
    }
    else{
        return r+b;
    }
}
int RSA::modulo1(int a,int n){
	int q, r;
	q = a/n;
	r = a - n*q;
	if (r<0){
		return r+n;
	}
}


ZZ RSA::gene(){
    ZZ e;
    e=(rand()%100);
    while(mcd(e,fin)!=1){
        e=(rand()%100);
    }
    return e;
}

ZZ RSA::expmod(ZZ base,ZZ exp,ZZ mod){
  ZZ resultado;resultado=1;
  while(exp!=0){
    base=modulo(base,mod);
    if(exp-((exp>>1)<<1)==1){
      resultado=modulo(base*resultado,mod);
    }
    if(base==1){
        return resultado;
    }
    base=base*base;
    exp=exp>>1;
  }
  return resultado;
}

ZZ RSA::eu_ext(ZZ a,ZZ b){
    ZZ a_inicial;a_inicial=a;
    ZZ t1,t2,r,q;t1=0,t2=1,r=1,q=0;
    ZZ t;t=0;
    while(r>0){
        q=a/b;
        r=a-q*b;
        a=b;
        b=r;
        t=t2;
        t2=t1-(q*t2);
        t1=t;
    }
    if(t1<0){
        t1=t1+a_inicial;
    }
    return t1;
}


ZZ RSA::resto_chino(ZZ a, ZZ b, ZZ N){
    ZZ d;d=b;
    ZZ dp,dq,p1,p2,q1,q2,b1,b2;
    dp=modulo(d,(p-1));//HALLAR exponente dp
    b1=modulo(a,p);//mod para recudir base dp
    b1=exp(b1,dp);
    b1=modulo(b1,p);//hallar el dp
    //asdasdsad
    dq=modulo(d,(q-1));//hallar exp dq
    b2=modulo(a,q);//reducir base
    b2=exp(b2,dq);
    b2=modulo(b2,q);//hallar dq
   //parte2
    p1=N/p;
    q1=eu_ext(p1,p);
    p2=N/q;
    q2=eu_ext(p2,q);
    ZZ result=modulo(modulo((b1*p1*q1),N)+modulo((b2*p2*q2),N),N);
    return result;


}
string RSA::ZZa_STR(ZZ a){
    stringstream buffer;
    buffer << a;
    return buffer.str();
}

ZZ RSA::STRa_ZZ(string str){
    ZZ num(INIT_VAL,str.c_str());
    return num;
}

string RSA::INTa_STR(int a){
    stringstream ss;
    ss<<a;
    return ss.str();
}

string RSA::add_0(ZZ num,int K){
    stringstream ss;
    string num_=ZZa_STR(num);
    ss<<setfill('0')<<setw(K)<<num_;
    return ss.str();
}


vector<int>RSA::criba(int  max_,vector<int> &primo){

    int min_=((pow(2,max_))/2);
    max_=pow(2,max_);

    vector<bool> array(max_,true);

    int  i,k;
    for (i=2;i<sqrt(max_);i++){
        if (array[i]==true){
            for (k=2;i*k<max_;k++){
                array[i*k]=false;
            }
        }
    }
    for (i=min_;i<max_;i++){
        if (array[i] == true){
            primo.push_back(i);
        }
    }
}

string RSA::codificar(string mensaje){
    ZZ tamLe;
    tamLe=alfabeto.find(alfabeto.size()-1);
    tamLe=(ZZa_STR(tamLe)).size();

    int tamN=(ZZa_STR(n-1)).size();
    int k=tamN-1;

    string men,s,s1,b;
    ZZ a,pos;
    for(int j=0;j<mensaje.size();j++){
        a=(alfabeto.find(mensaje[j]));
        s=add_0(a,(INTa_STR(alfabeto.find(alfabeto[alfabeto.size()-1])).size()));
        s1=s1+s;
    }

    if(modulo1(s1.size(),k)!=0){
        s1=s1+INTa_STR(alfabeto.find("w"));
        //s1=s1+"33";
        while(modulo1(s1.size(),k)!=0){
            //s1=s1+"33";
            s1=s1+INTa_STR(alfabeto.find("w"));
        }
    }
    for(int i=0;i<s1.size();i+=k){
        s=s1.substr(i,k);
        a=STRa_ZZ(s);
        pos=expmod(a,keye,n);
        b=add_0(pos,tamN);
        //cout<<"MEE:"<<b;
        men=men+b;
    }
    return men;
}

string RSA::decodificar(string mensaje){
    ZZ tamLe;
    tamLe=alfabeto.find(alfabeto.size()-1);
    tamLe=(ZZa_STR(tamLe)).size();

    int tamN=(ZZa_STR(n-1)).size();
    int k=tamN-1;

    int i=0;
    int num;
    string men,s,b,ss;
    ZZ a,pos;
    while(i<mensaje.size()){
        s=mensaje.substr(i,tamN);
        a=STRa_ZZ(s);
        pos=expmod(a,keyd,n);
        ss=add_0(pos,k);
        b=b+ss;
        i+=tamN;
    }
    for(int j=0;j<b.size();j+=(INTa_STR(alfabeto.find(alfabeto[alfabeto.size()-1])).size())){
    s=b.substr(j,(INTa_STR(alfabeto.find(alfabeto[alfabeto.size()-1])).size()));//
    num=atoi(s.c_str());
    ss=alfabeto[num];
    men=men+ss;
    }
    return men;
}

void RSA::Print(string men){
    ofstream save;
    string name="cifrado.txt";
    save.open(name.c_str());
    save<<men;
    save.close();
}

void RSA::Print1(string men){
    ofstream save;
    string name="decifrado.txt";
    save.open(name.c_str());
    save<<men;
    save.close();
}

int main(){

/*RSA receptor(15);
RSA emisor(receptor.get_e(),receptor.get_n());

cout<<"E: "<<receptor.get_e()<<endl;
cout<<"N: "<<receptor.get_n()<<endl;
cout<<"P: "<<receptor.get_p()<<endl;
cout<<"Q: "<<receptor.get_q()<<endl;


string mensaje,mensaje1;
cout<<"MENSAJE: ";
getline(cin,mensaje);

mensaje1=emisor.codificar(mensaje);
cout<<"CIFRADO: "<<mensaje1<<endl;

mensaje=receptor.decodificar(mensaje1);
cout<<"DESCIFRADO: "<<mensaje<<endl;

emisor.Print(mensaje1);
*/


//////////////////

RSA receptor(14);
RSA emisor(receptor.get_e(),receptor.get_n());

int ancho=100;
int alto=100;
CImg<unsigned char> imagen;

string rgb;
imagen=emisor.Binarizar("bart.bmp",rgb);
emisor.Print(rgb);
string temp;

temp=receptor.decodificar(rgb);
receptor.Print1(temp);

CImg<unsigned char> e=receptor.armar(rgb,ancho,alto);

e.display();
e.save("cifrado.bmp");
//CImg<unsigned char> e=im.desarmar(rgb,ancho,alto);

int ancho1=50;
int alto1=50;

CImg<unsigned char> d=receptor.desarmar(temp,ancho1,alto1);

d.display();
d.save("decifrado.bmp");





//ca1=

/*
CImg<unsigned char> im;
imagen=im.imagen("imagen2.bmp",120));
Matrix<int> A(im.height(),im.width());
GuardarImg(A,im);
ims.display("Imagen");*/


return 0;
}
// grimaldi
