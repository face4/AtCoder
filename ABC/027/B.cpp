#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int sum[n] = {};
    cin >> sum[0];
    
    for(int i = 1; i < n; i++){
        cin >> sum[i];
        sum[i] += sum[i-1];
    }

    if(sum[n-1]%n != 0){
        cout << -1 << endl;
    }else{
        int unit = sum[n-1]/n;
        int ans = 0;
        for(int i = 0; i < n-1; i++){
            if(sum[i] != unit*(i+1))    ans++;
        }
        cout << ans << endl;
    }

    return 0;
}