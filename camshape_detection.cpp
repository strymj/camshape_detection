#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main(void)
{
	vector<double> x;
	vector<double> y;
	double theta_step = M_PI/300;
	double r0 = 1;
	double k = 1;
	double gain = 0.1;
	double r_step = 0.0001;
	double rp = r0;
	double xp = r0;
	double yp = 0;
	double ap = 0;
	double bp = 0;
	double la;
	double lpa;
	double absla;
	double alphaa;
	double betaa;
	double aa;
	double ba;
	double xa;
	double ya;
	double ra;

	cout<<"theta,"<<"x,"<<"y,"<<"alpha,"<<"beta,"<<"a,"<<"b,"<<"l,"<<"lp,"<<"abs(l-lp),"<<endl;
	
	for(double theta=0+theta_step; theta<M_PI; theta+=theta_step) {

		double min_dl = r0*10000;

		for(double r=rp*0.99; r<rp*1.01; r+=r_step) {
			double x = r * cos(theta);
			double y = r * sin(theta);
			double alpha = atan(gain * sin(theta)/k*r*r);
			double beta = theta + M_PI/2 - alpha;
			double a = -1/tan(beta);
			double b = y - a*x; 
			double xc = - (b-bp)/(a-ap);
			double yc = a*xc + b;
			double l = pow(x-xc,2) + pow(y-yc,2); 
			double lp = pow(xp-xc,2) + pow(yp-yc,2); 
			if(fabs(l-lp) < min_dl)	{
				min_dl = fabs(l-lp);
				la = l;
				lpa = lp;
				alphaa = alpha;
				betaa = beta;
				absla = fabs(l-lp);
				aa = a;
				ba = b;
				xa = x;
				ya = y;
				ra = r;
			}
		}
		xp = xa;
		yp = ya;
		rp = ra;
		cout<<theta<<","
			<<xa<<","
			<<ya<<","
			<<alphaa<<","
			<<betaa<<","
			<<aa<<","
			<<ba<<","
			<<la<<","
			<<lpa<<","
			<<absla<<","
			<<endl;

	}
cout<<tan(M_PI*2/3)<<endl;

	return 0;
}
