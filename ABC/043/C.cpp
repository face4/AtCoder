#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int main(){
    int n;
    cin >> n;

    int A[n];
    for(int i = 0; i < n; i++)  cin >> A[i];

    // 愚直
    int ans = INT_MAX;
    for(int i = -100; i <= 100; i++){
        int tmp = 0;
        for(int j = 0; j < n; j++){
            tmp += (i-A[j])*(i-A[j]);
        }
        ans = min(tmp, ans);
    }

    cout << ans << endl;
    return 0;
}