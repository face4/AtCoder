// 凸関数なので三分探索
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

double p;

double takahashi(double x){
    return x + p/(pow(2.0, x/1.5));
}

int main(){
    cin >> p;

    double l = 0.0, r = p;
    while(r-l > 0.000000001){
        double mida = (2*l+r)/3.0, midb = (l+2*r)/3.0;
        if(takahashi(mida) < takahashi(midb))   r = midb;
        else                                    l = mida;
    }

    cout << fixed << setprecision(12) << takahashi(l) << endl;

    return 0;
}