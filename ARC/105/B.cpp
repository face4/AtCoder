#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];
    cout << accumulate(v.begin(), v.end(), v[0], [](int a, int b)->int{return gcd(a,b);}) << endl;
    return 0;
}