#include<iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int cnt[100001] = {};
    int a;
    for(int i = 0; i < 2*m; i++) cin >> a, cnt[a]++;
    for(int i = 0; i < 100001; i++){
        if(cnt[i]%2){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}