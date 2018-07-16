#include<iostream>
#include<map>
using namespace std;

typedef long long ll;

ll mod = 1e9+7;

int main(){
    int n;
    cin >> n;

    if(n == 1){
        cout << 1 << endl;
        return 0;
    }

    map<int,int> fact;
    for(int i = 2; i <= n; i++){
        int tmp = i;
        for(int j = 2; tmp != 1 && j <= i; j++){
            while(tmp%j == 0){
                fact[j]++;
                tmp /= j;
            }
        }
    }

    ll accum = 1;
    for(pair<int,int> p : fact){
        accum = (accum*(p.second+1)) % mod;
    }

    cout << accum << endl;
    
    return 0;
}