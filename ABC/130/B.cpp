#include<iostream>
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    int l[n];
    for(int i = 0; i < n; i++)  cin >> l[i];
    int ans = 1;
    int pos = 0;
    for(int i = 0; i < n; i++){
        pos += l[i];
        if(pos <= x)    ans++;
    }
    cout << ans << endl;
    return 0;
}