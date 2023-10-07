#include<iostream>
#include<fstream>
#include<cmath>
#include<vector>
using namespace std;
int main(){
    int n;
    ifstream in("inputtut7q1.txt");
    in>>n;
    vector<double>x(n);
    vector<double>Y(n);
    for(int i=0;i<n;i++){in>>x[i];}
    for(int i=0;i<n;i++){in>>Y[i];}
    in.close();
    double sy;
    for(int i=0;i<n;i++){
        sy += Y[i];
    }
    vector<vector<double>>X(n,vector<double>(2));
    vector<vector<double>>Xt(2,vector<double>(n)); //X transpose 
    vector<vector<double>>XtX(2,vector<double>(2)); //Xt*X
    vector<vector<double>>XtXinv(2,vector<double>(2)); //Xt*X^-1
    for(int i=0;i<n;i++){
        X[i][0] = 1;
        X[i][1] = x[i];
    }
    
    for(int i=0;i<n;i++){
        Xt[0][i] = 1;
        Xt[1][i] = x[i];
    }

    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<n;k++){
                XtX[i][j]  += Xt[i][k]*X[k][j];
            }
        }
    }
    double DetXtx = (XtX[0][0]*XtX[1][1])-(XtX[0][1]*XtX[1][0]); // determinant of Xt*X
    XtXinv[0][0] = (XtX[1][1])/DetXtx;
    XtXinv[1][1] = (XtX[0][0])/DetXtx;
    XtXinv[0][1] = (-1)*((XtX[0][1])/DetXtx);
    XtXinv[1][0] = (-1)*((XtX[1][0])/DetXtx);
         
    vector<vector<double>>XtXinvXt(2,vector<double>(n)); //(Xt*X)^-1*Xt
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<2;k++){
                XtXinvXt[i][j]  += XtXinv[i][k]*Xt[k][j];
            }
        }
    }
    vector<double>phi(2); //(Xt*X)^-1*Xt*Y  
    for(int i=0;i<2;i++){
        for(int k=0;k<n;k++){
            phi[i] += XtXinvXt[i][k]*Y[k];
        }
    }
    double a0=phi[0],a1=phi[1];
    vector<double>ypredicted(n);
    for(int i=0;i<n;i++){
        ypredicted[i] = a0 + (a1*x[i]);
    }
    double st,sr,r;
    double ybar = sy/n;
    for(int i=0;i<n;i++){
        sr += pow((Y[i]-ypredicted[i]),2);
        st += pow((Y[i]-ybar),2);
    }
    ofstream out("OutputTut7Q1P2.txt");
    out<<"Value of a0 = "<<a0<<" & value of a1 is = "<<a1<<endl;
    out<<"The model equation (y-predicted) is: y = "<<a0<<" + ("<<a1<<")x\n";
    out<<"Correlation Coefficient is = "<<(sqrt((st-sr)/st))<<endl;
    return 0;
}