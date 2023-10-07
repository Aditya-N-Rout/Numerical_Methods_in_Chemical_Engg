#include<iostream>
#include<vector>
#include<cmath>
#include<fstream>
using namespace std;
    double fn(double x){
       return ((exp(x))/3);
    }
int main(){
    ifstream  in("inputtut4t2.txt");
    double x0;
    in>>x0;
    double xi =  fn(x0);
    int steps = 0;
    double tol = 1e-5;
    double sol;
    while(abs(xi-x0)>tol){
       x0=xi;
       xi = fn(x0);
       steps++;
    }
    sol = xi;
    ofstream out("Outputtut4qn4.txt");
    out<<"\nThe solution in FPI method is = "<< sol<<endl;
    out<<"The number of iterations in FPI method is = "<< steps<<endl;
    out.close();
 return 0;
}