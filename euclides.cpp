#include <iostream>

using namespace std;

int mod (int a,int n){
	int q, r;
	q = a/n;
	r = a - n*q;
	if (r<0){
		return r+n;
	}
}


int MCD (int m,int n){
	int  r , s;
	if(m==n){
        return m;
    }
	if(n==0){
        return m;
    }
	while(r>0){
		s = r;
		r = mod(m,n);
		m = n;
		n = r;
		//cout<<MCD(m,n)<<endl;
	}
	return s;
}

main (){
	int a=250,n=111;
	cout<<mod(a,n)<<endl;
	cout<<MCD(a,n)<<endl;
	//cout << a%n;
}
