#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const ll mod = 998244353;

ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a%b);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    bool np[1000000] = {};
    vector<int> p;
    for(int i = 2; i < 1000000; i++){
        if(np[i])   continue;
        p.push_back(i);
        for(int j = i+i; j < 1000000; j += i)   np[j] = true;
    }

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    
    return 0;
}