#include<iostream>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    int ans = 0, tmp = 1;
    while(tmp < b){
        ans++, tmp += a-1;
    }
    cout << ans << endl;
    return 0;
}