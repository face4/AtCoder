#include<iostream>
#include<cmath>
#include<iomanip>
#include<vector>
#include<cfloat>
using namespace std;

const double EPS = 0.000001;
const double PI = acos(0.0)*2.0;

int main(){
    int n;
    cin >> n;
    double x[n], y[n];
    double ret = DBL_MAX;
    for(int i = 0; i < n; i++)  cin >> x[i] >> y[i];
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            double mx = (x[i]+x[j])/2.0, my = (y[i]+y[j])/2.0;
            double r = sqrt(pow(x[i]-mx, 2.0)+pow(y[i]-my, 2.0));
            bool valid = true;
            vector<bool> in(n, 0);
            for(int k = 0; k < n; k++){
                in[k] = sqrt(pow(x[k]-mx,2.0)+pow(y[k]-my,2.0)) <= r+EPS;
                valid &= in[k];
            }
            if(valid)   ret = min(ret, r);
            for(int k = 0; k < n; k++){
                if(in[k])   continue;
                // x[i], x[j], x[k]
                double a = x[j]-x[i];
                double b = x[k]-x[j];
                double c = y[j]-y[i];
                double d = y[k]-y[j];
                double X = -(x[i]*x[i]-x[j]*x[j]+y[i]*y[i]-y[j]*y[j]);
                double Y = -(x[j]*x[j]-x[k]*x[k]+y[j]*y[j]-y[k]*y[k]);
                double cy = X/2*b - Y/2*a;
                cy /= (b*c-a*d);
                double cx = (X/2-c*cy)/a;
                double radius = sqrt(pow(x[k]-cx,2.0)+pow(y[k]-cy,2.0));
                if(radius > r){
                    r = radius;
                    mx = cx;
                    my = cy;
                }
            }
            valid = true;
            for(int k = 0; k < n; k++){
                valid &= sqrt(pow(x[k]-mx,2.0)+pow(y[k]-my,2.0)) <= r+EPS;
            }
            if(valid)   ret = min(ret, r);
        }
    }
    cout << fixed << setprecision(12) << ret << endl;
    return 0;
}