#include<iostream>
using namespace std;

int main(){
    int a, b, x, l[41] = {}, r[41] = {};
    cin >> a >> b;
    for(int i = 0; i < a; i++){
        cin >> x;
        l[x]++;
    }
    for(int i = 0; i < b; i++){
        cin >> x;
        r[x]++;
    }

    int ans = 0;
    for(int i = 10; i < 41; i++)    ans += min(l[i],r[i]);

    cout << ans << endl;
    return 0;
}