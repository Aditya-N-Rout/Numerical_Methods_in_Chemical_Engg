#include<iostream>
#include<fstream>
#include<cmath>
#include<vector>
#include<cstdlib>
using namespace std;
int main(){
    int n;
    ifstream in("inputtut7q1.txt");
    in>>n;
    vector<double>x(n);
    vector<double>y(n);
    vector<double>ypredicted(n);
    vector<double>xpredicted(n);
    for(int i=0;i<n;i++){in>>x[i];}
    for(int i=0;i<n;i++){in>>y[i];}
    in.close();
    vector<double>xy(n);
    vector<double>x2(n);
    vector<double>y2(n);
    for(int i=0;i<n;i++){
        xy[i]=x[i]*y[i]; 
        x2[i]=x[i]*x[i];
        y2[i]=y[i]*y[i];
    }
    double Sxy,Sx,Sy,Sx2,Sy2; //here S notation is used for summation, and the following variable is 
                          // the variable whose sum is being taken
    for(int i=0;i<n;i++){
        Sxy+=xy[i];  //sum of x*y
        Sx+=x[i]; // sum of x
        Sy+=y[i];     // sum of y
        Sx2+=x2[i];    //sum of x^2
        Sy2+=y2[i];  //sum of y^2
    }
    double a0,a1,b0,b1;
    //TAKING x as independent variable
    a1 = ((n*Sxy)-(Sx*Sy))/((n*Sx2)-(pow(Sx,2)));
    a0 = (Sy/n)-((Sx/n)*a1);
    //Taking y as independent variable
    b1 =  ((n*Sxy)-(Sx*Sy))/((n*Sy2)-(pow(Sy,2)));
    b0 =  (Sx/n)-((Sy/n)*b1);
    for(int i=0;i<n;i++){
        ypredicted[i] = a0 + (a1 * x[i]); //predicted values if y is dependent
        xpredicted[i] = b0 + (b1 * y[i]); //predicted values if x is dependent
    }
    double Stx,Sty,Srx,Sry;
    for(int i=0;i<n;i++){
        Sry += pow((y[i]-ypredicted[i]),2);//y predicted case
        Srx += pow((x[i]-xpredicted[i]),2);//x predicted case
        Stx += pow((x[i]-(Sx/n)),2);
        Sty += pow((y[i]-(Sy/n)),2);
    }
    double r1,r2; //CORRELATION COEFFICIENT IN y-PREDICTED & x-PREDICTED CASE respectively
    r1 = sqrt((Sty-Sry)/Sty);
    r2 = sqrt((Stx-Srx)/Stx);
    ofstream out("Outputtut7q1.txt");
    out<<"Value of a0 = "<<a0<<" & value of a1 for y-predicted case is = "<<a1<<endl;
    out<<"Correlation Coefficient for y-predicted case is = "<<r1<<endl;
    out<<"The model equation (y-predicted) is: y = "<<a0<<" + "<<a1<<"x\n";
    out<<"Value of a0 = "<<(-1*(b0/b1))<<" & value of a1 for x-predicted case is = "<<(1/b1)<<endl; 
    out<<"Correlation Coefficient for x-predicted case is = "<<r2<<endl;
    out<<"The model equation (x-predicted) is: y = "<<(-1*(b0/b1))<<" + "<<(1/b1)<<"x\n";
    out.close();
    
    ofstream datafile1("tut7orgValues.txt");  // To store original values in a file for graph
    ofstream datafile2("tut7YPredictedValues.txt");  //Y predicted values file
    ofstream datafile3("tut7XPredictedValues.txt");  //X predicted values file
    for(int i=0;i<n;i++){
        datafile1<<x[i]<<" "<<y[i]<<endl;
    }
    for(int i=0;i<n;i++){
        datafile2<<x[i]<<" "<<ypredicted[i]<<endl;
    }
    for(int i=0;i<n;i++){
        datafile3<<xpredicted[i]<<" "<<y[i]<<endl;
    }
    datafile1.close();
    datafile2.close();
    datafile3.close(); 
    
    string command ="gnuplot -persist -e \""
                    "set xlabel 'x axis';"
                    "set ylabel 'y axis';"
                    "plot 'tut7orgValues.txt' with points title 'Data',"
                     " 'tut7YPredictedValues.txt' with lines title 'Y Predicted',"
                     " 'tut7XPredictedValues.txt' with lines title 'X Predicted'\"";
    system(command.c_str());
    return 0;
}