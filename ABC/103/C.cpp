#include<iostream>
#include<numeric>
using namespace std;

int main(){
    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i++)  cin >> a[i];
 
    int ans = accumulate(a, a+n, 0);
    cout << ans-n << endl;

    return 0;
}