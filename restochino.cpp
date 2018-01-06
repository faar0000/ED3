#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int eu_ext(int a, int b){
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
int mod (int a,int n){
	int q, r;
	q = a/n;
	r = a - n*q;
	if (r<0){
		return r+n;
	}
}

int resto_chino(int a,int b,int N){
    int d=103;
    int dp,dq,p1,p2,q1,q2,b1,b2;
    dp=mod(d,(11-1));//HALLAR exponente dp
    b1=mod(a,11);//mod para recudir base dp
    b1=pow(b1,dp)+1;
    b1=mod(b1,11);//hallar el dp
    //asdasdsad
    dq=mod(d,(13-1));//hallar exp dq
    b2=mod(a,13);//reducir base
    b2=pow(b2,dq)+1;
    b2=mod(b2,13);//hallar dq
   //parte2
    p1=N/11;
    q1=eu_ext(p1,11);
    p2=N/13;
    q2=eu_ext(p2,13);
    int Do=mod((b1*p1*q1+b2*p2*q2),N);
    return Do;
}
int main() {


    cout<<"expm : "<<resto_chino(115,103,143)<<endl;


    return 0;
}
