#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;

int main(){
    int n;
    cin >> n;
    n *= 2;
    
    vector<int> x(n);
    for(int i = 0; i < n; i++)  cin >> x[i];

    sort(x.begin(), x.end());
    for(int i = 1; i < n; i+=2) x[i] = 0;

    cout << accumulate(x.begin(), x.end(), 0) << endl;
    return 0;
}