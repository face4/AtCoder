#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> prime;
    bool nonprime[101] = {};
    nonprime[0] = nonprime[1] = true;
    for(int i = 2; i < 101; i++){
        if(nonprime[i]) continue;
        prime.push_back(i);
        for(int j = i+i; j < 101; j+=i) nonprime[j] = true;
    }

    int count[101] = {};

    int n;
    cin >> n;

    for(int i = 2; i <= n; i++){
        int tmpi = i;
        for(int p : prime){
            while(tmpi % p == 0)    tmpi /= p, count[p]++;
            if(tmpi == 1)   break;
        }
    }

    int ans = 0;
    for(int i = 2; i < 100; i++){
        if(count[i] >= 74)  ans++;
        for(int j = i+1; j < 100; j++){
            if(count[i] >= 4 && count[j] >= 14) ans++;
            if(count[i] >= 24 && count[j] >= 2) ans++;
            if(count[j] >= 4 && count[i] >= 14) ans++;
            if(count[j] >= 24 && count[i] >= 2) ans++;
            for(int k = j+1; k < 100; k++){
                if(count[i] >= 2 && count[j] >= 4 && count[k] >= 4) ans++;
                if(count[i] >= 4 && count[j] >= 2 && count[k] >= 4) ans++;
                if(count[i] >= 4 && count[j] >= 4 && count[k] >= 2) ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}