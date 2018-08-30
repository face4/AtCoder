#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<numeric>
#include<iomanip>
#include<cmath>
using namespace std;

typedef long long ll;
const double EPS = 0.00001;
#define Equals(a,b) abs(a-b) < EPS

ll getcombination(int a, int b){
    ll ret = 1;
    for(int i = 0; i < b; i++){
        ret *= (a-i);
        ret /= (i+1);
    }
    return ret;
}

int main(){
    int n, a, b;
    ll v;

    cin >> n >> a >> b;
    vector<ll> value(n);
    map<ll, int> appear;

    for(int i = 0; i < n; i++){
        cin >> value[i];
        appear[value[i]]++;
    }

    sort(value.rbegin(), value.rend());

    ll accum = accumulate(value.begin(), value.begin() + a, 0ll);
    map<ll, int> used;
    for(int i = 0; i < a; i++)  used[value[i]]++;

    double maxave = accum / (double)a;
    ll ans = 1;

    for(auto x : used){
        ans *= getcombination(appear[x.first], used[x.first]);
    }

    for(int i = a; i < b; i++){
        if(Equals(value[i],maxave)){
            used[value[i]]++;
            ll tmp = 1;
            for(auto x : used){
                tmp *= getcombination(appear[x.first], used[x.first]);
            }
            ans += tmp;
        }else{
            break;
        }
    }

    cout << fixed << setprecision(7) << maxave << endl << ans << endl;

    return 0;
}