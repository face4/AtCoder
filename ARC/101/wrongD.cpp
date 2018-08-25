// 予め昇順に並んでる数列にのみ正しい答えを返すはず
// サンプルケースは何故か〇

#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;

    int a[n];
    set<pair<int, int>> rev;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        rev.insert({a[i], i});
    }

    ll med = ((ll)n*(n+1))/2 /2 + 1;
    ll accum = 0;
    int ans;

    for(auto p : rev){
        int pos = p.second;
        // a single + normal + distorted
        accum += 1 + min(pos-0, n-1-pos) + min(max(0, pos-1-0), n-pos-1);
        if(accum >= med){
            ans = p.first;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}