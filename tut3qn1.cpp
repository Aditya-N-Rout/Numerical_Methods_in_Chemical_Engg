#include<iostream>
#include<fstream>
#include<cmath>
#include<vector>
#include<iomanip>
using namespace std;
int main(){
    ifstream in("inputtut3qn1.txt");
    int n;
    in>>n;
    int m = n;
    int q = n;
    int sgauss = 0;
    int sjacobi = 0;
    vector<vector<double>>a(n, vector<double>(n));
    vector<double>b(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            in>>a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        in>>b[i];
    }
    in.close();
    double tol = 1e-8;
    vector<double>solgauss(n);
    vector<double>soljacobi(n);
    vector<double>oldsolg(n);
    vector<double>oldsolj(n);
  //GAUSS SIEDEL METHOD  
  while(m>0){
      //STORING THE OLD VALUES
      for(int p=0;p<n;p++){
        oldsolg[p]=solgauss[p];
      }
     //UPDATING THE SOLUTION VALUES 
     for(int k=0;k<100;k++){
     for(int i=0;i<n;i++){
     double sumsub=0;
     double sumsup=0;
      for(int j=0;j<i;j++){
        sumsub += ((a[i][j])*(solgauss[j]));
      }
      for(int j=i+1;j<n;j++){
        sumsup += ((a[i][j])*(oldsolg[j]));
      }

      solgauss[i]=(b[i]-sumsub-sumsup)/(a[i][i]);

     }
    }
    sgauss++; //INCREASING THE NUMBER OF STEPS
    //CHECKING THE CONVERGENCE
    for(int t=0;t<n;t++){
      if(abs(solgauss[t]-oldsolg[t])<tol){
         m--;
      }
    }
  }
  //JACOBI METHOD
   while(q>0){
      //STORING THE OLD VALUES
      for(int p=0;p<n;p++){
        oldsolj[p]=soljacobi[p];
      }
     //UPDATING THE SOLUTION VALUES 
     for(int k=0;k<100;k++){
     for(int i=0;i<n;i++){
     double sumsub=0;
     double sumsup=0;
      for(int j=0;j<i;j++){
        sumsub += ((a[i][j])*(oldsolj[j]));
      }
      for(int j=i+1;j<n;j++){
        sumsup += ((a[i][j])*(oldsolj[j]));
      }

      soljacobi[i]=(b[i]-sumsub-sumsup)/(a[i][i]);

     }
    }
    sjacobi++; //INCREASING THE NUMBER OF STEPS
    //CHECKING THE CONVERGENCE
    for(int t=0;t<n;t++){
      if(abs(soljacobi[t]-oldsolj[t])<tol){
         q--;
      }
    }
  }
  //FOR OUTPUT FILE
    ofstream out("OutputTut3Qn1.txt");
    out<<"The solution in gauss siedel is = \n";
    for(int i=0;i<n;i++){
      out<<solgauss[i]<<endl;
    }
    out<<"The total number of gauss siedel iterations is = "<<sgauss<<endl;
    out<<"The solution in jacobi iteration is = \n";
    for(int i=0;i<n;i++){
      out<<soljacobi[i]<<endl;
    }
    out<<"The total number of jacobi iterations is = "<<sjacobi<<endl;
    return 0;
}