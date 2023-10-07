#include<iostream>
#include<fstream>
#include<cmath>
#include<vector>
using namespace std;
int main(){
    int n;
    ifstream in("inputtut7q1.txt");
    in>>n;
    vector<double>X(n);
    vector<double>y(n);
    for(int i=0;i<n;i++){in>>X[i];}
    for(int i=0;i<n;i++){in>>y[i];}
    in.close();
    double sx;
    for(int i=0;i<n;i++){
        sx += X[i];
    }
    vector<vector<double>>Y(n,vector<double>(2));
    vector<vector<double>>Yt(2,vector<double>(n)); //Y transpose 
    vector<vector<double>>YtY(2,vector<double>(2)); //Yt*Y
    vector<vector<double>>YtYinv(2,vector<double>(2)); //Yt*Y^-1
    for(int i=0;i<n;i++){
        Y[i][0] = 1;
        Y[i][1] = y[i];
    }
    
    for(int i=0;i<n;i++){
        Yt[0][i] = 1;
        Yt[1][i] = y[i];
    }

    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<n;k++){
                YtY[i][j]  += Yt[i][k]*Y[k][j];
            }
        }
    }
    double DetYtY = (YtY[0][0]*YtY[1][1])-(YtY[0][1]*YtY[1][0]); // determinant of Yt*Y
    YtYinv[0][0] = (YtY[1][1])/DetYtY;
    YtYinv[1][1] = (YtY[0][0])/DetYtY;
    YtYinv[0][1] = (-1)*((YtY[0][1])/DetYtY);
    YtYinv[1][0] = (-1)*((YtY[1][0])/DetYtY);
         
    vector<vector<double>>YtYinvYt(2,vector<double>(n)); //(Yt*Y)^-1*Yt
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<2;k++){
                YtYinvYt[i][j]  += YtYinv[i][k]*Yt[k][j];
            }
        }
    }
    vector<double>phi(2); //(Xt*X)^-1*Xt*Y  
    for(int i=0;i<2;i++){
        for(int k=0;k<n;k++){
            phi[i] += YtYinvYt[i][k]*X[k];
        }
    }

    double b0=phi[0],b1=phi[1];
    double a0 = (-1)*(b0/b1), a1 = 1/b1;
    vector<double>xpredicted(n);
    for(int i=0;i<n;i++){
        xpredicted[i] = b0 + (b1*y[i]);
    }
    double st,sr,r;
    double xbar = sx/n;
    for(int i=0;i<n;i++){
        sr += pow((X[i]-xpredicted[i]),2);
        st += pow((X[i]-xbar),2);
    }
    ofstream out("OutputTut7Q1P2B.txt");
    out<<"Value of a0 = "<<a0<<" & value of a1 is = "<<a1<<endl;
    out<<"The model equation (x-predicted) is: y = "<<a0<<" + ("<<a1<<")x\n";
    out<<"Coefficient of determination is = "<<(((st-sr)/st))<<endl;
    return 0;
}