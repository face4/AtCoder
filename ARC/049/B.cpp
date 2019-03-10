#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int n;
    cin >> n;
    int x[n], y[n], c[n];
    for(int i = 0; i < n; i++)  cin >> x[i] >> y[i] >> c[i];
    double l = 0, r = 1000000001;
    while(r-l > 0.000001){
        double mid = (l+r)/2;
        double lx = -100001, ly = -100001, hx = 100001, hy = 100001;
        for(int i = 0; i < n; i++){
            lx = max(lx, x[i]-mid/c[i]);
            ly = max(ly, y[i]-mid/c[i]);
            hx = min(hx, x[i]+mid/c[i]);
            hy = min(hy, y[i]+mid/c[i]);
        }
        if(lx <= hx && ly <= hy)    r = mid;
        else                        l = mid;
    }
    cout << fixed << setprecision(12) << r << endl;
    return 0;
}