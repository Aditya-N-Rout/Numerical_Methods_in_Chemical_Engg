#include<iostream>
#include<vector>
#include<cmath>
#include<fstream>
#include<cstdlib> 
using namespace std;

double fn1(double x, double y, double z){
    return (x*x)+(y*y)+(z*z)-4;
}
double fn2(double x, double y, double z){
    return (x*x)+(y*y)-1;
}
double fn3(double x, double y, double z){
    return (4*y*y)+(z*z)-4;
}
int main(){
    ifstream in("inputtut5.txt");
    double x,y,z;
    in>>x;
    in>>y;
    in>>z;
    in.close();
    double tol = 1e-8;
    int t=2;
    int steps = 0;
    double x0,y0,z0;
    x0=0.866025;
    y0=0.5;
    z0=1.73205;
    ofstream datafile1("tut5trueerr.txt");
    ofstream datafile2("tut5relerr.txt");
    while(t>0){
        vector<vector<double>> j(3, vector<double>(3)); 
        vector<double> jinvFn(3);
        vector<double>fnval(3);
        steps++;
        fnval[0]=fn1(x,y,z);
        fnval[1]=fn2(x,y,z);
        fnval[2]=fn3(x,y,z);
        j[0][0]=2*x;
        j[0][1]=2*y;
        j[0][2]=2*z;
        j[1][0]=2*x;
        j[1][1]=2*y;
        j[1][2]=0.0;
        j[2][0]=0.0;
        j[2][1]=8*y;
        j[2][2]=2*z;
        vector<vector<double>> jinv(3, vector<double>(3));
        for(int i=0;i<3;i++){
            jinv[i][i]=1; 
        }
       //MAKING INVERSE OF JACOBIAN
        int n=3;
        for(int i=0;i<n;i++){
        int rowmax=i;
        for(int k=i+1;k<n;k++){
            if(abs(j[k][i])>abs(j[rowmax][i])){
                rowmax=k;
            }
        }
        if(rowmax != i){
            swap(j[i],j[rowmax]);
            swap(jinv[i],jinv[rowmax]);
        }
        double const g = j[i][i];
        //making pivot element 1
        for(int k=0;k<n;k++){
            j[i][k] = j[i][k]/g;
            jinv[i][k] = jinv[i][k]/g;
        }
        //inverse transformations
        for(int k=0;k<n;k++){
            if(k!=i){
            double const fact = j[k][i];
            for(int p=0;p<n;p++){
              j[k][p]-=(fact*j[i][p]);
              jinv[k][p]-=(fact*jinv[i][p]);
            }
            }
        }
       } //INVERSE COMPLETE
        for(int i=0;i<3;i++){
         for(int l=0;l<3;l++){
            jinvFn[i] += (jinv[i][l] * fnval[l]); 
        }
        }
        x = x - jinvFn[0];
        y = y - jinvFn[1];
        z = z - jinvFn[2];
        double relerr  = abs(jinvFn[0])+abs(jinvFn[1])+abs(jinvFn[2]);
        double trueerr = abs(x0-x)+abs(y0-y)+abs(z0-z);
        if(relerr<tol){
         t=0;
        }
        datafile1<<steps<<" "<<trueerr<<endl;
        datafile2<<steps<<" "<<relerr<<endl;
    }
    string command =  "gnuplot -persist -e \""
                    "set xlabel 'Iteration Number';"
                    "set ylabel 'True Error';"
                    "set logscale x; set logscale y;"
                    "plot 'tut5trueerr.txt' with points title 'TrueError in NR'\"";
    system(command.c_str());
    string command1 =  "gnuplot -persist -e \""
                    "set xlabel 'Iteration Number';"
                    "set ylabel 'Rel Error';"
                     "set logscale x; set logscale y;"
                    "plot 'tut5relerr.txt' with points title 'RelError in NR'\"";
    system(command1.c_str());
    ofstream out("outputtut5.txt");
    out<<"The solution is = "<<x<<", "<<y<<", "<<z<<endl;
    out<<"number of iterations = "<<steps;
    out.close();
    return 0;
}