#include<iostream>
#include<cfloat>
#include<cmath>
using namespace std;

int main(){
    int n;
    cin >> n;

    int a[n], sum = 0;
    for(int i = 0; i < n; i++)  cin >> a[i], sum += a[i];

    double d = (double)sum / n;
    double dist = DBL_MAX;
    int ans = -1;

    for(int i = 0; i < n; i++){
        double tmp = abs(d-(double)a[i]);
        if(tmp < dist){
            dist = tmp;
            ans = i;
        }
    }

    cout << ans << endl;

    return 0;
}