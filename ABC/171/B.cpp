#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    for(int i = 0; i < n; i++)  cin >> p[i];
    sort(p.begin(), p.end());
    cout << accumulate(p.begin(), p.begin()+k, 0) << endl;
    return 0;
}