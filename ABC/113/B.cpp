#include<iostream>
#include<cfloat>
#include<cmath>
using namespace std;

int main(){
    int n;
    double t, a;
    cin >> n >> t >> a;

    int ans = -1;
    double dist = DBL_MAX;

    double h;
    for(int i = 1; i <= n; i++){
        cin >> h;
        h = t-h*0.006;
        double tmp = abs(h-a);
        if(tmp < dist){
            dist = tmp;
            ans = i;
        }
    }

    cout << ans << endl;

    return 0;
}