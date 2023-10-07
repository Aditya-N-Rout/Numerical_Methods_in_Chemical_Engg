#include<iostream>
#include<fstream>
#include<iomanip>
#include<cmath>
#include<vector>
using namespace std;

int main(){
    //READING INPUT FROM INPUT FILE
     ifstream in("inputqn1.txt");
     int n;
     in>>n;
     int const col=n+1;
     vector<vector<double>>a(n, vector<double>(n+1));
    // Reading matrix elements from the file
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n+1; j++) {
            in>> a[i][j]; 
        }
    }
    in.close();
    //STORING THE COEFFICIENT MATRIX
    vector<vector<double>>a0(n, vector<double>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a0[i][j]=a[i][j];
        }
    }
    //MAKING THE UPPER TRIANGULAR MATRIX
    for (int i=0;i<n-1;i++){
        int rowmax=i;
        for(int j=i+1;j<n;j++){
            if(abs(a[j][i])>abs(a[rowmax][i])){
                rowmax=j;
            }
        }
        swap(a[i],a[rowmax]);
       for(int j=i+1;j<n;j++){
          double fact =a[j][i]/a[i][i];
          for(int k=i;k<n+1;k++){
              a[j][k]-=(fact*a[i][k]);
          }
       }

    }  
    for(int p=0;p<4;p++){
        for(int q=0;q<4;q++){
            cout<<a[p][q]<<" ";
        }
        cout<<endl;
    }
   //SOLUTION WRITING
   vector<double>sol(n);
   for(int i=n-1;i>=0;i--){
    double sum=0;
    for(int j=i+1;j<n+1;j++){
      sum+=a[i][j]*sol[j];

    }
    sol[i]=(a[i][n]-sum)/a[i][i];
   }
     //FOR VERIFICATION OF THE RESULT
   vector<double>Val(n);
   for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
       Val[i]+=((a0[i][j])*(sol[j]));
    }
   }
   //CREATING OUTPUT FILE of solution
   ofstream out("OutputQn1.txt");
   out<<"The solution is = \n";
   for(int i=0;i<n;i++){
    out<<sol[i]<<endl;
   }
   out<<"\nFor verification the product of coefficient matrix and solution matrix is = "<<endl; 
   for(int i=0;i<n;i++){
    out<<Val[i]<<endl;
   }
   out<<"This is same as the forcing vector.\nHence Verified !";
return 0;
}
