#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int main()
{
    string mensaje="abcdefghijklmnñopqrstuvxyz1234567890ABCDEFGHIJKLMNÑOPQRSTUVXYZ$&";
    int a=sqrt(mensaje.size());
    //cout<<a<<"kekekeke";
    int t=mensaje.size();
    //cout<<"jojojojjo"<<t;
    string A[a][a];
	string m=mensaje;
	string g=mensaje;
	int q=0;
	int x=0,c=a,p=0,z=1;
	while(q<t){
            //c=7,z=2,p=1,q=12//x=1
            do{
                if(x>=p && x<c){
                    for(int k=c-1;k>=z-1;k--){
                        //cout<<"corde"<<p<<k<<endl;
                        //cout<<mensaje[q];
                        A[p][k]=mensaje[q];//01234567//282930313233//48
                        q++;//12345678//293031323334/49
                        x++;//12345678//234567
                        //cout<<A[p][k];
                    }
                    //cout<<endl;
                }
                else if(x>=c && x<2*c-1*z){
                    for(int k=z;k<=c-1;k++){
                        A[k][p]=mensaje[q];//891011121314//3435363738
                        q++;//9101112131415//3536373839
                        x++;//9101112131415//89101112
                        //cout<<A[k][p];
                    }
                    //cout<<endl;
                }
                else if(x>=2*c-1 && x<3*c-2*z){
                    for(int k=z;k<=c-1;k++){
                        A[c-1][k]=mensaje[q];//15161718192021//3940414243
                        q++;//16171819202122//4041424344
                        x++;//16171819202122//1314151617
                        cout<<A[c-1][k];
                    }
                    cout<<endl;
                }
                else if(x>=3*c-2*7 && x<4*c-4*z){
                    for(int k=c-2;k>=z;k--){
                        A[k][c-1]=mensaje[q];//222324252627//44454647
                        q++;//22232425262728//45464748
                        x++;//22232425262728//181920
                        //cout<<A[k][c-1]<<endl;
                    }
                }
            }while(x<4*c-4*z);
            p++;
            c--;
            x=z;
            z++;
    }
    cout<<A[0][0];

    return 0;
}
