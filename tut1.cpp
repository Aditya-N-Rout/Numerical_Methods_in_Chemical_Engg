#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main() {

	//Q1
	
	/*double pi = 3.14159265359;
	double x = 0.3 * pi;
	double trueval = cos(x);
	double tol = 1e-8;
	double sum = 0;
	double term = 1;
	int n = 0;
	while (abs(trueval - sum) >= tol){
		sum += term;
		term *= -(x) * (x) / ((2 * n + 1) * (2 * n + 2));
		n++;
	}
	cout << "Number of terms = " << n << endl;
	cout << "Approx Value = " <<setprecision(8)<<sum << endl;
	cout << "True Value = " << setprecision(8)<<trueval << endl; */

	


	//THE INFINITE SERIES Q2
  
	
	float pi = 3.14159265359;
	float trueval = (pow(pi, 4)) / 90;
    float sumfor = 0;
	float sumrev = 0;
	for (int i = 1; i <= 10000; i++) {
		sumfor += 1 / (pow(i, 4));
	}
	for (int i = 10000; i>0; i--) {
		sumrev += 1 / (pow(i, 4));
	}
	float TrueErrFor = 100 * (abs(trueval - sumfor) / trueval);
	float TrueErrRev = 100 * (abs(trueval - sumrev) / trueval);

	cout << "true value  is " <<setprecision(12)<< trueval << endl;
	cout << "forward sum is " <<setprecision(12)<< sumfor << endl;
	cout << "true percent relative error in forward sum is " <<setprecision(12)<< TrueErrFor<<" %" << endl;
	cout << "reverse sum is " << sumrev << endl;
	cout << "true percent relative error in reverse sum is " <<setprecision(12)<< TrueErrRev <<" %" << endl;



	//DIVIDE AND AVG METHOD
	/*
	double a = 5;
	double x = 0.005;
	double tol = 1e-6;
	double trueval = sqrt(a);
	while (abs(trueval - x) > tol) {
		double p = x;
		x = 0.5 * (x + (a / x));
		double tpre = 100 * ((abs(trueval - x)) / trueval);
		double apre = 100 * ((abs(p - x)) /p);
		cout << "true percent relative error is " << tpre << " %"<<endl;
		cout << "approx percent relative error is " << apre << " %"<<endl;
	}
	cout << "true value is " << trueval<<endl;
	cout << "calculated value is " <<x;
	
	 
	return 0;
    */
}
