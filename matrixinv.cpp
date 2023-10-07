#include<iostream>
#include<fstream>
#include<cmath>
#include<vector>
using namespace std;
int main (){
    
    ifstream in("inputmatrix.txt");
    int n;
    in>>n;
   
    vector<vector<double>> j(3, vector<double>(3));
    for(int i=0;i<n;i++){
        for(int p=0;p<n;p++){
            in>>j[i][p];
        }
    } 
    in.close();
    vector<vector<double>> jinv(3, vector<double>(3));
    for(int i=0;i<n;i++){
        jinv[i][i]=1;
    }
 
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
    }
    ofstream out("inversemat.txt");
    for(int i=0;i<n;i++){
        for(int k=0;k<n;k++){
            out<<jinv[i][k]<<" ";
        }
        out<<endl;
    }
    out.close();
    return 0;
}