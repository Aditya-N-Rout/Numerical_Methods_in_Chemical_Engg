#include<iostream>
#include<fstream>
#include<cmath>
#include<vector>
using namespace std;
int main() {
	//HERE WE HAVE TAKEN y2 AS THE DEPENDENT VARIABLE
	ifstream in("inputtut7q2.txt");
	int N;
	in >> N;
	double x2;
	vector<double>x1(N);
	for (int i = 0; i < N; i++) {
		in >> x1[i];
	}
	in >> x2;
	vector<double>y1(N);
	for (int i = 0; i < N; i++) {
		in >> y1[i];
	}
	vector<double>y2(N);
	for (int i = 0; i < N; i++) {
		in >> y2[i];
	}
	vector<vector<double>>j(4, vector<double>(4));
	vector<double>Y(4);
	double Sx1, Sx2, Sy1, Sx1x1, Sx2x2, Sy1y1, Sx1x2, Sx1y1, Sy1x2;
	double Sy2, Sy2x1, Sy2x2, Sy2y1;
	 
	j[0][0] = N;
	j[0][1] = Sx1;
	j[0][2] = Sx2;
	j[0][3] = Sy1;

	j[1][0] = Sx1;
	j[1][1] = Sx1x1;
	j[1][2] = Sx1x2;
	j[1][3] = Sx1y1;

	j[2][0] = Sx2x2;
	j[2][1] = Sx1x2;
	j[2][2] = Sx2x2;
	j[2][3] = Sy1x2;

	j[3][0] = Sy1;
	j[3][1] = Sx1y1;
	j[3][2] = Sy1x2;
	j[3][3] = Sy1y1;

	Y[0] = Sy2;
	Y[1] = Sy2x1;
	Y[2] = Sy2x2;
	Y[3] = Sy2y1;

	Sx2 = N * x2;
	Sx2x2 = N * (pow(x2, 2));
	for (int i = 0; i < N; i++) {
		Sx1 += x1[i];
		Sy1 += y1[i];
		Sy2 += y2[i];
		Sx1x1 += (x1[i] * x1[i]);
		Sy1y1 += (y1[i] * y1[i]);
		Sx1x2 += (x1[i] * x2);
		Sy1x2 += (y1[i] * x2);
		Sx1y1 += (x1[i] * y1[i]);
		Sy2x1 += (y2[i] * x1[i]);
		Sy2x2 += (y2[i] * x2);
		Sy2y1 += (y2[i] * y1[i]);
	}
	 vector<vector<double>>jinv(4, vector<double>(4));
	 for (int i = 0; i < 3; i++) {
		 jinv[i][i] = 1;
	 }
	 //MAKING INVERSE OF JACOBIAN
	 int n = 4;
	 for (int i = 0; i < n; i++) {
		 int rowmax = i;
		 for (int k = i + 1; k < n; k++) {
			 if (abs(j[k][i]) > abs(j[rowmax][i])) {
				 rowmax = k;
			 }
		 }
		 if (rowmax != i) {
			 swap(j[i], j[rowmax]);
			 swap(jinv[i], jinv[rowmax]);
		 }
		 double const g = j[i][i];
		 //making pivot element 1
		 for (int k = 0; k < n; k++) {
			 j[i][k] = j[i][k] / g;
			 jinv[i][k] = jinv[i][k] / g;
		 }
		 //inverse transformations
		 for (int k = 0; k < n; k++) {
			 if (k != i) {
				 double const fact = j[k][i];
				 for (int p = 0; p < n; p++) {
					 j[k][p] -= (fact * j[i][p]);
					 jinv[k][p] -= (fact * jinv[i][p]);
				 }
			 }
		 }
	 } //INVERSE COMPLETE
	 //Multiplying jinv with Y
	 vector<double>A(4);
	 for (int i = 0; i < 4; i++) {
		 for (int j = 0; j < 4; j++) {
			 A[i] += (jinv[i][j] * Y[j]);
		 }
	 }
	 double a0, a1, a2, a3;
	 a0 = A[0];
	 a1 = A[1];
	 a2 = A[2];
	 a3 = A[3];


	ofstream out("outputtut7q2.txt");
	out << "The curve's predicted equation is : (" << a0 << ") + (" << a1 << ")x1 + (" << a2 << ")x2 + (" << a3 << ")y1" << endl;
	return 0;
}