#include<iostream>
using namespace std;

int main(){
    int ans = 0;
    int s, e;
    for(int i = 0; i < 3; i++){
        cin >> s >> e;
        ans += s/10*e;
    }
    cout << ans << endl;
    return 0;
}