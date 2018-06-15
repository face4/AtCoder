#include<iostream>
#include<map>
using namespace std;

#define MOD 1000000007

int main(){
    int n;
    cin >> n;

    map<int, int> m;
    int x;
    bool flag = true;

    for(int i = 0; i < n; i++){
        cin >> x;
        m[x]++;
        if(m[x] > 2){
            flag = false;
            break;
        }
    }

    if(!flag){
        cout << 0 << endl;
        return 0;
    }

    if(n%2 == 1){
        if(m[0] != 1){
            flag = false;
        }
        for(int i = 2; i <= n/2*2; i += 2){
            if(m[i] != 2)   flag = false;
        }
    }else{
        if(m[0] != 0){
            flag = false;
        }
        for(int i = 1; i <= 2*(n/2-1)+1; i += 2){
            if(m[i] != 2)   flag = false;
        }
    }

    if(!flag){
        cout << 0 << endl;
        return 0;
    }

    int ans = 1;
    for(int i = 0; i < n/2; i++){
        ans *= 2;
        ans %= MOD;
    }

    cout << ans << endl;
    return 0;
}