#include<iostream>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    int res = 1;
    for(int i = 0; i < n; i++){
        res += min(res,k);
    }

    cout << res << endl;
    return 0;
}