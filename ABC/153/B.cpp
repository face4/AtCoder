#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

int main(){
    int h, n;
    cin >> h >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];
    cout << (h <= accumulate(v.begin(), v.end(), 0) ? "Yes" : "No") << endl;
    return 0;
}