// 天才成分が多すぎて100%は理解できていない
#include<iostream>
using namespace std;
typedef long long ll;

ll solve(ll a, ll b){
    if(a == b)  return 2*(a-1); // これは自明
    ll upper = a*b-1;
    ll l = 1, r = 1ll<<31;  // 最悪ケースがmid*midくらいなので探索範囲の上限は1e9*2くらい
    while(r-l > 1){
        ll mid = (l+r)/2;   // 2回のコンテストで[1,mid]位だった人のみからなるマッチング
        ll tmp = (mid/2+1)*(mid-(mid/2+1)+1);   // このマッチングにおける最悪のケース
        if(tmp > upper) r = mid;
        else            l = mid;
    }
    return l-1; // lはmin(a,b)以上なのでmin(a,b)の分を引く(多分)
}

int main(){
    int q;
    cin >> q;
    while(q-- > 0){
        ll a, b;
        cin >> a >> b;
        cout << solve(a,b) << endl;
    }
    return 0;
}