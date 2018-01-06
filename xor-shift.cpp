#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <time.h>

void SeedXorShift()
{
    time_t timer= time(NULL);
    struct tm y2k;
    ZZ seconds;

    y2k.tm_hour=0;
    y2k.tm_min=0;
    y2k.tm_sec=0;
    y2k.tm_year=100;
    y2k.tm_mon=0;
    y2k.tm_mday=1;
    seconds=conv<ZZ>(difftime(tiemr,mktime(&y2k)));
    xorshift_x=seconds;
    xorshift_y=seconds^123456789;
    xorshift_z=seconds<<31;
    xorshift_w=seconds>>28321;

}
ZZ XorShift()
{
    ZZ tmp;
    tmp=xorshift_x^(xorshift_x<<11);
    xorshift_x=xorshift_y;
    xorshift_y=xorshift_z;
    xorshift_z=xorshift_w;
    xorshift_w=xorshift_w^(xorshift_w>>19)^(tmp^(tmp>>8));
    return Modulo(xorshift_w,conv<ZZ>(MAX_XOR));
}
SeedXorShift();
for (int i=0;i<10;i++)
{
    cout<<XorShift()<<endl;
}
