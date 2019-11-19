#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++)  v.push_back(i);
    vector<double> x(n), y(n);
    for(int i = 0; i < n; i++)  cin >> x[i] >> y[i];
    double ans = 0;
    do{
        double tmp = 0;
        for(int i = 1; i < n; i++){
            tmp += sqrt(pow(x[v[i]]-x[v[i-1]], 2.0) + pow(y[v[i]]-y[v[i-1]], 2.0));
        }
        ans += tmp;
    }while(next_permutation(v.begin(),v.end()));
    for(int i = 1; i <= n; i++) ans /= i;
    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}