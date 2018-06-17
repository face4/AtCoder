#include<iostream>
using namespace std;

int main(){
    int n, a, res = 1<<21;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a;

        int cnt = 0;
        while(a%2 == 0){
            cnt++;
            a /= 2;
        }

        res = min(res, cnt);
    }

    cout << res << endl;
    return 0;
}