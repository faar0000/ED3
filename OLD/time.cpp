#include <iostream>
#include <string>
#include <stdio.h>
#include <stdio.h>
#include <vector>
#include <time.h>

using namespace std;

string int_bin(int num){
    string binario="";
    if(num >0){
        while(num > 0){
            if(num%2==0){
                binario="0"+binario;
            }
            else{
                binario="1"+binario;
            }
            num=(int)num/2;
        }
    }else if(num==0){
        binario="0";
    }
    return binario;
}

string suma(string lista,int pos){
    for(int i=pos;i<lista.size();i++;){
        lista[i+1]=(lista[i-1]+lista[i-2])%2;
    }
    return suma;
}

string seed(int bits){
    string s,ss;
    s=int_bin(getTime());
    ss=s.substr(0,bits);
    return ss;
}

vector<int> generar_aleatorio(string seed,int bits ,int particiones ,int aleatorios){
    string s;
    string temp;
    =ss;
    s=suma(s,seed.size())
    b=b+seed;
    for(int i =)


}



string getTime ()
{
    time_t timeObj;
    time(&timeObj);
    tm *pTime = gmtime(&timeObj);
    char buffer[100];
    sprintf(buffer, "%d%d%d", pTime->tm_hour, pTime->tm_min, pTime->tm_sec);
    return buffer;
}

int main() {

}
