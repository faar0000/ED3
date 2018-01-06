#include <iostream>
using namespace std;


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
int main() {

    cout<<"expm : "<<expomod(667,1271,2537)<<endl;
    cout<<"expm : "<<expomod(1947,1271,2537)<<endl;
    cout<<"expm : "<<expomod(671,1271,2537)<<endl;
    return 0;
}
