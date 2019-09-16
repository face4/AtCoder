// 1 - RollingHashによる解法　O(N(logN)^2)

#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

struct RollingHash{
    static const ull base = 1000000007;
    vector<ull> hash, power;

    RollingHash(const string &s){
        int n = (int)s.size();
        hash.assign(n+1, 0);
        power.assign(n+1, 1);
        for(int i = 0; i < n; i++){
            hash[i+1] = hash[i]*base + s[i];
            power[i+1] = power[i]*base;
        }
    }

    ull get(int l, int r){
        return hash[r] - hash[l] * power[r-l];
    }
};

int main(){
    int n;
    string s;
    cin >> n >> s;

    RollingHash rh(s);
    auto f = [&](int x)->bool{
        map<ull,vector<int>> m;
        for(int i = 0; i+x <= n; i++){
            ull p = rh.get(i, i+x);
            if(m[p].empty())    m[p].push_back(i);
            else if(i-m[p].front() >= x)    return true;
        }
        return false;
    };

    int l = 0, r = n;
    while(r-l > 1){
        int mid = (l+r)/2;
        if(f(mid))  l = mid;
        else        r = mid;
    }

    cout << l << endl;

    return 0;
}