#include<iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int l = 1, r = n;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        l = max(a, l);
        r = min(b, r);
    }
    cout << max(0, r-l+1) << endl;
    return 0;
}