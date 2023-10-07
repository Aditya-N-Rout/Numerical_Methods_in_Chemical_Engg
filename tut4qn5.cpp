#include<iostream>
#include<vector>
#include<cmath>
#include<fstream>
using namespace std;
    double fn(double x){
       return x- ((exp(x))/3);
    }
    double fnd(double x){
       return 1 - ((exp(x))/3);
    }
int main(){
    ifstream in("inputtut4t2.txt");
    double x0;
    in>>x0;
    double sol;
    double steps = 0;
    double xi = (x0)- ((fn(x0))/(fnd(x0)));
    double tol = 1e-5;
    while(abs(xi-x0)>tol){
      x0=xi;
      xi = x0- ((fn(x0))/(fnd(x0)));
      steps++;
    }
    sol = xi;
    ofstream out("Outputtut4qn5.txt");
    out<<"The solution in NR method is = "<< sol<<endl;
    out<<"The number of iterations in NR method is = "<< steps<<endl;
    out.close();
 return 0;
}