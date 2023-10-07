#include<iostream>
#include<fstream>
#include<cmath>
#include<vector>
#include<iomanip>
#include<cstdlib> 
using namespace std;
int main(){
    ifstream in("inputtut3qn2.txt");
    int n;
    in>>n;
    int m = n;
    int q = n;
    int sgauss = 0;
    int sjacobi = 0;
    vector<vector<double>>a(n, vector<double>(n));
    vector<double>b(n);
    vector<double>solgauss(n);
    vector<double>soljacobi(n);
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
        soljacobi[i]=solgauss[i];
    }
    in.close();
    ofstream datafile1("datagauss.txt");
    ofstream datafile2("datajacobi.txt");

    vector<double>oldsolg(n);
    vector<double>oldsolj(n);
    double tol = 1e-8;
    
  //GAUSS SIEDEL METHOD  
  for (int m=0;m<25;m++){
    double sqErrgauss=0;
    double err = 0;
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
      err = abs(solgauss[i]-oldsolg[i]);
      sqErrgauss += ((err)*(err));
       
     }
    }
    double p = sqrt(sqErrgauss);
   
    sgauss++; //INCREASING THE NUMBER OF STEPS
    //TAKING THE DATA POINTS
    datafile1<<sgauss<<" "<<p<<endl;
    

  }
  string command =  "gnuplot -persist -e \""
                    "set xlabel 'Iteration Number';"
                    "set ylabel 'Root Sum Square Error';"
                    "plot 'datagauss.txt' with points title 'Error in GS'\"";

  system(command.c_str());

  //JACOBI METHOD
   for(int q=0;q<25;q++){
     double sqErrjac=0;
     double errj = 0;
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
      errj = abs(soljacobi[i]-oldsolj[i]);
      sqErrjac += (errj*errj);

     }
    }
    sjacobi++; //INCREASING THE NUMBER OF STEPS
    datafile2<<sjacobi<<" "<<sqrt(sqErrjac)<<endl;

  }
  string command1 = "gnuplot -persist -e \""
                    "set xlabel 'Iteration Number';"
                    "set ylabel 'Root Sum Square Error';"
                    "plot 'datajacobi.txt' with points title 'Error in Jacobi'\"";
  system(command1.c_str());
  
    return 0;
}