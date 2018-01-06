#include <iostream>
using namespace std;

int menp=26,p=29, r=5,c1,c2 ,n=77, e1=2, e2, d=12,sy,sx;

int expomod(int base, int exp,int mod) {
    int bina=0;
    int resul=1;
    int d=base%mod;
    if(exp%2==1){
        resul=base;
    }
    exp=exp/2;
    while (exp>0){
        bina= exp%2;
        d=(d*d)%mod;
        if(bina==1){
            resul=(d*resul)%mod;
        }
        exp=exp/2;
    }
    return resul;

}
int gcd(int a, int b){
    int r,s,t,r1,r2,s1,s2,t1,t2,q;
    r1=a;r2=b;
    s1=1;s2=0;
    t1=0;t2=1;
    while(r2>0){
        q=r1/r2;
        //HALLA EL MCD
        r=r1-(q*r2);
        r1=r2; r2=r;
        //HALLA VALORES DEL X
        s=s1-(q*s2);
        s1=s2; s2=s;
        //HALLA VALORES DEL Y
        t=t1-(q*t2);
        t1=t2; t2=t;
    }
    sx=t1;//retornamos X
    sy=s1;//retornamos Y
    d=r1;

}
int inverso(int a,int b){
    int invert=0;
    gcd(a,b);
    if(sy>1){
        invert=sy;
    }
    else{
            invert=b+sy;
    }
    return invert;
}
int generae2(){
    e2=expomod(e1,d,p);
    return e2;
}

int clave1(){
    c1=expomod(e1,r,p);
    return c1;
}
int km(){
    int km1=expomod(e2,r,p);
    return km1;
}

int clave2() {
    c2=(menp*km())%p;
}
int inicio(){
    generae2();
    return e2;
}
int cifrado(){
    clave1();
    int n =clave2();
    return n;
}
int des1(){
    int km2=expomod(c1,d,p);
    return km2;
}
int descrifado(){
    int kinver=des1();
    kinver=inverso(kinver,p);
    int ca= (c2*kinver)%p;
    return ca;
}

int main(){
    cout<<"M a cifrar: "<<menp<<endl;
    cout<<"e2 generado:"<<inicio()<<endl;
    //cout<<generae2();
   //cout<<gene2<<endl;
   cout<<"Mensaje cifrado: "<<cifrado()<<endl;
    cout<<"Descifrado: "<<descrifado()<<endl;
}
