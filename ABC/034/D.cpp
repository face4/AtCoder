#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> w(n), p(n);
    for(int i = 0; i < n; i++)  cin >> w[i] >> p[i];

    double l = 0, r = 100.0;
    int cnt = 100;
    while(cnt-- > 0){
        double mid = (l+r)/2;
        vector<double> tmp(n);
        for(int i = 0; i < n; i++){
            tmp[i] = (w[i]*(p[i]-mid));
        }
        sort(tmp.rbegin(), tmp.rend());
        if(accumulate(tmp.begin(), tmp.begin()+k, 0.0) >= 0.0)  l = mid;
        else r = mid;
    }

    cout << fixed << setprecision(12) << l << endl;

    return 0;
}