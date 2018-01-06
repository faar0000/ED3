#include <iostream>
#include <stdio.h>
using namespace std;




int expomod(int base,int exp,int mod){
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



int expmod(int base, int exp,int mod) {
    int bina=0;
    int resul=1;
    int d=base%mod;
    cout<<"exp"<<"\t"<<"expmod2"<<"\t"<<"base2"<<"\t"<<"resultado"<<"\t"<<"exp/2"<<endl;
    cout<<exp<<"\t"<<bina<<"\t"<<d<<"\t"<<resul<<"\t"<<"\t"<<exp/2<<endl;
    bina=exp%2;
    if(bina==1){
        resul=d;
    }
    exp=exp/2;

    while (exp>0){
        //cout<<exp<<"\t"<<bina<<"\t"<<d<<"\t"<<resul<<"\t"<<exp/2<<endl;
        bina= exp%2;
        d=(d*d)%mod;
        if(bina!=0){
            resul=(d*resul)%mod;
        }
        exp=exp/2;
        cout<<"   "<<"\t"<<bina<<"\t"<<d<<"\t"<<resul<<"\t"<<"\t"<<exp<<endl;
    }
    return resul;

}



int main() {


    cout<<"expm : "<<expomod(15,7,143)<<endl;
  //  cout<<"expm : "<<expomod(1947,1271,2537)<<endl;
    //cout<<"expm : "<<expomod(671,1271,2537)<<endl;

    return 0;
}
