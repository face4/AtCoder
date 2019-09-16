#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n-1);
    for(int i = 0; i < n; i++)  cin >> a[i];
    for(int i = 0; i < n; i++)  cin >> b[i];
    for(int i = 0; i < n-1; i++)    cin >> c[i];
    int ans = accumulate(b.begin(), b.end(), 0);
    for(int i = 1; i < n; i++){
        if(a[i]-1 == a[i-1])    ans += c[a[i-1]-1];
    }
    cout << ans << endl;
    return 0;
}