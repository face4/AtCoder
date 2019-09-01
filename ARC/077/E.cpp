#include<iostream>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++)  cin >> a[i], a[i]--;
    
    multiset<pair<int,int>> s;
    vector<int> v[m];
    ll sum = 0, tmp = 0;
    for(int i = 0; i+1 < n; i++){
        if(a[i] < a[i+1])   v[a[i]].push_back(a[i+1]), sum += a[i+1]-a[i];
        else                v[a[i]].push_back(a[i+1]+m), s.insert({a[i+1], a[i+1]+m-a[i]}), sum += a[i+1]+m-a[i], tmp += m-1-a[i]-1;
    }
    
    ll ans = 1ll<<60;
    for(int i = 0; i < m; i++){
        tmp += s.size();
        ans = min(ans, sum-tmp);
        while(s.size() > 0 && s.begin()->first == i){
            tmp -= s.begin()->second-1;
            s.erase(s.begin());
        }
        for(int c : v[i]){
            s.insert({c, c-i});
            tmp--;
        }
    }
    
    cout << ans << endl;

    return 0;
}