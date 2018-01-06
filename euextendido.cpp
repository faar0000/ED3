#include <iostream>
unsigned t0,t1;

using namespace std;
int gcd(int a, int b);
int sx,ty;

int main()
{


    cout<<"MCD: "<<gcd(1024,480)<<" ";
    cout<<"X: "<<sx<<" "<<"Y: "<<ty<<endl;
}

int gcd(int a, int b){
    int r,s,t,r1,r2,s1,s2,t1,t2,q;

    r1=a;r2=b;
    s1=1;s2=0;
    t1=0;t2=1;
    cout<<"r"<<"\t"<<"s"<<"\t"<<"t"<<"\t"<<"r1"<<"\t"<<"r2"<<"\t"<<"s1"<<"\t"<<"s2"<<"\t"<<"t1"<<"\t"<<"t2"<<"\t"<<"q"<<endl;


    while(r2>0){
        cout<<r<<"\t"<<s<<"\t"<<t<<"\t"<<r1<<"\t"<<r2<<"\t"<<s1<<"\t"<<s2<<"\t"<<t1<<"\t"<<t2<<"\t"<<q<<endl;
        ///////////////
        q=r1/r2;//inicializamos el valor de q
        ///////////////
        r=r1-q*r2;//iniciamos r como el valor "a" -el cociente por "b"
        r1=r2;r2=r;//actualizamos posiciones r1 ahora es b ,r2 ahora es el modulo a y b
        ///////////////
        s=s1-q*s2;//hallamos el modulo de s1 y s2
        s1=s2;s2=s;//actualizamos su posicion
        ///////////////
        t=t1-q*t2;//hallamos el modulo de t1 y t2
        t1=t2;t2=t;//actualizamos su posicion
        ///////////////
        //(s1  0)
        //(0  s2)


    }

    sx=s1;//retornamos X
    ty=t1;//retornamos Y
    return r1;

}
