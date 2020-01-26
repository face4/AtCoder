// 自力AC出来たかと思ったら4ケース落ちた
// 最初plusの要素をa_i降順、b_i降順でソートしていたのが原因
// b_i <= b_{i+1}であるようなiを考えると、
// a_i - b_i + a_{i+1}　と　a_{i+1} - b_{i+1} + a_{i}　の大小
// 関係はb_iとb_{i+1}の大小にのみ依存する
// もちろんb_{i+1}の方が大きいので最適性を失わずにi,i+1番目を
// swap出来る -> よってplusの要素はb_i降順
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<pii> minus, even, plus;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        if(a-b < 0){
            minus.push_back({a,b});
        }else if(a == b){
            even.push_back({a,b});
        }else if(a-b > 0){
            plus.push_back({b,a});
        }
    }
    sort(minus.begin(), minus.end());
    sort(plus.rbegin(), plus.rend());
    ll ans = 0, now = 0;
    for(auto p : minus){
        now += p.first;
        ans = max(ans, now);
        now -= p.second;
    }
    for(auto p : even){
        now += p.first;
        ans = max(ans, now);
        now -= p.second;
    }
    for(auto p : plus){
        now += p.second;
        ans = max(ans, now);
        now -= p.first;
    }
    cout << ans << endl;
    return 0;
}
