#include<iostream>
#include<fstream>
#include<cmath>
#include<vector>
#include<iomanip>
using namespace std;
int main(){
    ifstream in("inputtut3qn3.txt");
    int n;
    in>>n;
    int m = n;
    int q = n;
    double w = 1.5;
    int sgauss = 0;
    int ssor = 0;
    vector<vector<double>>a(n, vector<double>(n));
    vector<double>b(n);
    vector<double>solgauss(n);
    vector<double>solsor(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            in>>a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        in>>b[i];
    }
    for(int i=0;i<n;i++){
        in>>solgauss[i];
        solsor[i]=solgauss[i];
    }
    in.close();
    double tol = 1e-8;
   
    vector<double>oldsolg(n);
    vector<double>oldsols(n);
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
  //SOR METHOD
   while(q>0){
      //STORING THE OLD VALUES
      for(int p=0;p<n;p++){
        oldsols[p]=solsor[p];
      }
     //UPDATING THE SOLUTION VALUES 
     for(int k=0;k<100;k++){
     for(int i=0;i<n;i++){
     double sumsub=0;
     double sumsup=0;
      for(int j=0;j<i;j++){
        sumsub += ((a[i][j])*(solsor[j]));
      }
      for(int j=i+1;j<n;j++){
        sumsup += ((a[i][j])*(oldsols[j]));
      }

      solsor[i]=(b[i]-sumsub-sumsup)/(a[i][i]);
      solsor[i]=(w*solsor[i])+((1-w)*oldsols[i]);

     }
    }
    ssor++; //INCREASING THE NUMBER OF STEPS
    //CHECKING THE CONVERGENCE
    for(int t=0;t<n;t++){
      if(abs(solsor[t]-oldsols[t])<tol){
         q--;
      }
    }
  }
    //FOR OUTPUT FILE
    ofstream out("OutputTut3Qn3.txt");
    out<<"The solution in gauss siedel is = \n";
    for(int i=0;i<n;i++){
      out<<solgauss[i]<<endl;
    }
    out<<"The total number of gauss siedel iterations is = "<<sgauss<<endl;
    out<<"The solution in SOR GS iteration is = \n";
    for(int i=0;i<n;i++){
      out<<solsor[i]<<endl;
    }
    out<<"The total number of SOR GS iterations is = "<<ssor<<endl;
    return 0;
}