#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int l = 1000, r = 0, a;
    for(int i = 0; i < n; i++){
        cin >> a;
        l = min(l, a);
        r = max(r, a);
    }

    cout << r-l << endl;
    return 0;
}