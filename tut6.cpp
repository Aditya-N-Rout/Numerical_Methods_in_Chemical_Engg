#include<iostream>
#include<cmath>
#include<vector>
#include<fstream>
using namespace std;
int main(){
    vector<double>a(4);
    double r,s;
    ifstream in("inputtut6.txt");
    for(int i=0;i<4;i++){
        in>>a[i];
    }
    in>>r;
    in>>s;
    in.close();
    double delr,dels;
    double errr=1,errs=1;
    double tol = 1e-5;
    vector<double>b(4);
    vector<double>c(4);
    ofstream out("outputtut6.txt");
    int k=0;
    while((errr+errs)>(tol)){
        
        k++;
        b[3]=a[3];
        b[2]=a[2]+(b[3]*r);
        b[1]=a[1]+(b[2]*r)+(b[3]*s);
        b[0]=a[0]+(b[1]*r)+(b[2]*s);
        c[3]=b[3];
        c[2]=b[2]+(c[3]*r);
        c[1]=b[1]+(c[2]*r)+(c[3]*s);
        c[0]=b[0]+(c[1]*r)+(c[2]*s);
        dels = ((-1*b[0])+((c[1]*b[1])/c[2]))/(c[2]-((c[1]*c[3])/c[2]));
        delr = ((-1*b[1])-(c[3]*dels))/c[2];
        errs = abs((dels/s)*100);
        errr = abs((delr/r)*100);
        r+=delr;
        s+=dels;
        out<<k<<"th iteration\n";
        out<<"Values of r and s are "<<r<<", "<<s<<" respectively\n";
        for(int i=0;i<4;i++){
            out<<"b"<<i<<" is = "<<b[i]<<endl;
        }
        out<<"dels = "<<dels<<endl;
        out<<"delr = "<<delr<<endl;
        out<<"errr = "<<errr<<endl;
        out<<"errs = "<<errs<<endl;
        
    }
    vector<double>root(3);
    root[0]=(-1)*(b[2]/b[3]);
    root[1]=0.5*(r+sqrt(pow(r,2)+(4*s)));
    root[3]=0.5*(r-sqrt(pow(r,2)+(4*s)));
    out<<"Positive roots are ";
    for(int i=0;i<3;i++){
        if(root[i]>0){
            out<<root[i]<<", ";
        }
    }
    


    return 0;
}