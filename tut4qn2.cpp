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
    //REGULA FALSI METHOD
    double solr = xl - (fn(xl))*((xr-xl)/(fn(xr)-fn(xl)));;
    int sreg=0;  
    while(abs(fn(solr))>tol) {
      sreg++;
      if((fn(xl)*fn(solr))<0){
            xr=solr;
        }else{
            xl=solr;
        }
     solr = xl - (fn(xl))*((xr-xl)/(fn(xr)-fn(xl)));
    }
    ofstream out("Outputtut4qn2.txt");
    out<<"\nThe solution in regula falsi method is = "<< solr<<endl;
    out<<"The number of iterations in regula falsi method is = "<< sreg<<endl;
    out.close();
 return 0;
}