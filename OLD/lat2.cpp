
#include <cmath>
#include <iostream>
#include <math.h>

using namespace std;

const double earth = 6378.135;  // in km
const double PI    = 4.0 * atan(1.0);

double GetDistance(double dLat1, double dLong1, double dLat0, double dLong0)
{
	double Radius=6371;
	double RadLat0=dLat0*(PI/180);
	double RadLong0=dLong0*(PI/180);
	double RadLat1=dLat1*(PI/180);
	double RadLong1=dLong1*(PI/180);
	double deltaLat=RadLat1-RadLat0;
	double deltaLong=RadLong1-RadLong0;
	double a=pow((sin(deltaLat/2)),2) + cos(RadLat0)*cos(RadLat1)*pow((sin(deltaLong/2)),2);
	double c=2*atan2(sqrt(a),sqrt(1-a));
	double d=Radius*c;
	double nDistance=d;
	return (nDistance);
}


int main(){
cout<<GetDistance(-16.3989709,-71.5365457,-16.3989840,-71.5364969)<<endl;
}
