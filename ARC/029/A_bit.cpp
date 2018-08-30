#include<iostream>
#include<numeric>
using namespace std;

int main(){
    int n;
    cin >> n;
    int t[n];
    for(int i = 0; i < n; i++)  cin >> t[i];
    int sum = accumulate(t, t+n, 0);

    int ans = sum;
    for(int i = 0; i < 1<<n; i++){
        int one = 0;
        for(int j = 0; j < n; j++)  if(i & 1<<j)    one += t[j];
        ans = min(ans, max(one,sum-one));
    }

    cout << ans << endl;
    return 0;
}