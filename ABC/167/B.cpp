#include<iostream>
using namespace std;

int main(){
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    int ret = 0;
    ret += min(a, k);
    ret -= max(0, k-a-b);
    cout << ret << endl;
    return 0;
}