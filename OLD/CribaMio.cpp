#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
vector<int> criba(int  max_){

    vector<int> primo;
    int min_=((pow(2,max_))/2);
    max_=pow(2,max_);

  //  int cantidad=max_-min_;
    vector<bool> array(max_,true);

    int  i,k;
    for (i=2;i<sqrt(max_);i+=1){
        if (array[i]==true){
            for (k=2;i*k<max_;k++){
                array[i*k]=false;
            }
        }
    }
    for (i=min_;i<max_;i++){
        if (array[i] == true){
            primo.push_back(i);
            cout<<i<<"-";
        }
    }

    return primo;
}

int main(){
    int a;
    a=15;
    criba(a);
    return 0;
}
