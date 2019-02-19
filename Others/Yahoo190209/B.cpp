#include<iostream>
using namespace std;

int main(){
    int cnt[4] = {};
    int a, b;
    for(int i = 0; i < 3; i++){
        cin >> a >> b;
        a--, b--;
        cnt[a]++, cnt[b]++;
    }
    int odd = 0;
    for(int i = 0; i < 4; i++)  odd += cnt[i]%2;
    if(odd <= 2)    cout << "YES" << endl;
    else            cout << "NO" << endl;
    return 0;
}