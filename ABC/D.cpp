#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<double> v;
    for(int i = 0; i < n; i++){
        double p;   cin >> p;
        v.push_back((p+1)/2.0);
    }
    double tmp = 0;
    for(int i = 0; i < k; i++){
        tmp += v[i];
    }
    double ret = tmp;
    for(int i = k; i < n; i++){
        tmp -= v[i-k];
        tmp += v[i];
        ret = max(ret, tmp);
    }
    cout << fixed << setprecision(12) << ret << endl;
    return 0;
}
