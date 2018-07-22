#include<iostream>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;

    int ans = min(abs(b-c) + abs(a-b), min(abs(c-a) + abs(b-c), abs(a-b) + abs(c-a)));

    cout << ans << endl;

    return 0;
}