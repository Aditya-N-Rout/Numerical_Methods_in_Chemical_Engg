#include<iostream>
#include<iomanip>
#include<fstream>
#include<cmath>
#include<vector>
using namespace std;

int main(){
    //READING INPUT FROM INPUT FILE
     ifstream in("inputqn2.txt");
     int n;
     in>>n;
     int const col=(2*n)+1;
     double **a = new double*[n];
    for (int i = 0; i < n; i++) {
        a[i] = new double[col];
    }
    // Reading matrix elements from the file
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <col; j++) {
            in>> a[i][j]; 
        }
    }

    in.close();
    //STORING THE COEFFICIENT MATRIX
    vector<vector<double>> a0(n, vector<double>(n));
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a0[i][j]=a[i][j];
        }
    }
    //Main functional Code of Program
    for (int i=0;i<n;i++){
        int rowmax=i;
        for(int j=i+1;j<n;j++){
            if(abs(a[j][i])>abs(a[rowmax][i])){
                rowmax=j;
            }
        }
        if(rowmax != i){
            swap(a[i],a[rowmax]);
        }
        double const g =a[i][i];

        //Making ith row pivot element 1
        for(int j=i;j<col;j++){
            a[i][j]=a[i][j]/g;
        }
        //TRANSFORMING THE ROWS
        for(int j=0;j<n;j++){
          double fact =a[j][i];
          if(j!=i){
          for(int k=i;k<col;k++){
              a[j][k]-=(fact*a[i][k]);
          }

          }
        }
    }
   
    //CHECKING A^(-1)*A=I
    vector<vector<double>> Inv(n, vector<double>(n));
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            Inv[i][j]=a[i][j+n+1];
        }
    }
 
   vector<vector<double>> Val(n, vector<double>(n));
   for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        for(int k=0;k<n;k++){
         Val[i][j]+=((Inv[i][(k)])*(a0[k][j]));
        }
     }
   }
   //CREATING OUTPUT FILE
   ofstream out("OutputQn2.txt");
   out<<"The solution is = \n";
   for(int i=0;i<n;i++){
    out<<a[i][n]<<endl;
   }
  //For Inverse of the matrix
   out<<"The Inverse is "<<endl;
   for (int i = 0; i <n;i++) {
        for (int j = n+1; j <col;j++) {
            out << a[i][j] << " ";
        }
       out<<endl;
    }
    out<<"The product of calculated inverse with the coefficient matrix is = "<<endl;
    for (int i = 0; i <n;i++) {
        for (int j = 0; j <n;j++) {
            out << Val[i][j] << " ";
        }
       out<<endl;
    }
    return 0;
}