#include<iostream>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int ret = 0;
    while(n > 0){
        ret++;
        n /= k;
    }
    cout << ret << endl;
    return 0;
}