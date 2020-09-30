#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> x, y;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        x.push_back(a+b);
        y.push_back(a-b);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    cout << max(*y.rbegin()-*y.begin(), *x.rbegin()-*x.begin()) << endl;
    return 0;
}