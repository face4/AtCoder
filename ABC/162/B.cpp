#include<iostream>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    ll ret = 0;
    for(int i = 1; i <= n; i++){
        if(i%3 > 0 && i%5 > 0)  ret += i;
    }
    cout << ret << endl;
    return 0;
}