#include <iostream>
#include <math.h>
using namespace std;

double theta_step = M_PI/10000;
double r0 = 0.03;  // [m]
double k = 500;    // [N/m]
double m = 0.3;    // [kg]
double g = 9.8;    // [m/s^2]
double l = 0.3;    // [m] 
double mu = m*g*l;

int main(void)
{
	cout<<"theta,"
		<<"sin(theta),"
		<<"x,"
		<<"y,"
		<<"alpha,"
		<<"beta,"
		<<"r,"<<endl;

	double r = r0;

	for(double theta=0; theta<M_PI; theta+=theta_step) {
		double x = r * cos(theta);
		double y = r * sin(theta);
		double alpha = atan(mu * sin(theta)/(k*r*r));
		double beta = theta + M_PI/2 - alpha;
		double a = tan(beta);
		double ap = tan(theta+theta_step);
		double b = y - a*x; 
		double xn = -b / (a-ap);
		double yn = ap * xn;
		double rn = sqrt(xn*xn+yn*yn);

		cout<<theta<<","
			<<k*r*r*tan(alpha)<<","
			<<x<<","
			<<y<<","
			<<alpha<<","
			<<beta<<","
			<<r<<","
			<<endl;

		r = rn;
	}

	return 0;
}
