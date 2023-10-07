#include<iostream>
#include<vector>
#include<cmath>
#include<fstream>
using namespace std;
    double fn(double x){
       return x-((exp(x))/3);
    }
int main(){
    ifstream in("inputtut4.txt");
    double g1;
    in>>g1;
    double g2;
    in>>g2;
    in.close();
    double xl,xr;
    if(fn(g1)<0){
      xr = g1;
      xl = g2;
    }else{
        xr=g2;
        xl=g1;
    }
    double tol = 1e-8;
    //BISECTION METHOD
    
    double sol = (xl+xr)/2;
    int sbic=0;  
    while(abs(fn(sol))>tol) {
      sbic++;
      if((fn(xl)*fn(sol))<0){
            xr=sol;
        }else{
            xl=sol;
        }
     sol = (xl+xr)/2;
    }
    ofstream out("Outputtut4qn1.txt");
    out<<"The solution in bisection method is = "<< sol<<endl;
    out<<"The number of iterations in bisection method is = "<< sbic<<endl;
    out.close();
    return 0;
}