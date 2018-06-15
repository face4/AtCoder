#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    int A[n];
    for(int i = 0; i < n; i++)  cin >> A[i];

    int l = 0, r = 0;
    int now_sum = 0;
    int now_xor = 0;
    long long ans = 0;

    while(l < n){
        while(r < n && (now_sum+A[r])==(now_xor^A[r])){
            now_sum += A[r];
            now_xor ^= A[r];
            r++;
        }
        
        ans += r-l;

        now_sum -= A[l];
        now_xor ^= A[l];
        l++;
    }

    cout << ans << endl;
    return 0;
}