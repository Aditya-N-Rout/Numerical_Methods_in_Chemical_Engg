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
    double tol = 1e-5;

    //SECANT METHOD

    int j=1;
    double sols = xl - ((fn(xl)*((xr-xl)/(fn(xr)-fn(xl)))));
    int ssec=0;  
   while(abs(sols - xl)>tol){
    xl = sols;
    sols = xl - ((fn(xl)*((xr-xl)/(fn(xr)-fn(xl)))));
    ssec ++;
   }
    ofstream out("Outputtut4qn3.txt");
    out<<"\nThe solution in secant method is = "<< sols<<endl;
    out<<"The number of iterations in secant method is = "<< ssec<<endl;
    out.close();
 return 0;
}