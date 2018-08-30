#include<iostream>
using namespace std;

int main(){
    int a[7], b[7];
    for(int i = 0; i < 7; i++)  cin >> a[i];
    for(int i = 0; i < 7; i++)  cin >> b[i];
    int ans = 0;
    for(int i = 0; i < 7; i++)  ans += max(a[i], b[i]);
    cout << ans << endl;
    return 0;
}