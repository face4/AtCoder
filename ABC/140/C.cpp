#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> b(n-1);
    for(int i = 0; i < n-1; i++)    cin >> b[i];
    int ans = b[n-2];
    for(int i = n-2; i >= 1; i--){
        ans += min(b[i], b[i-1]);
    }
    ans += b[0];
    cout << ans << endl;
    return 0;
}