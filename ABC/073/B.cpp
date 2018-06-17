#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int sum = 0, l, r;
    for(int i = 0; i < n; i++){
        cin >> l >> r;
        sum += r - l + 1;
    }

    cout << sum << endl;
    return 0;
}