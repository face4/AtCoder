#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<int> v;
    if(s[0] == '0') v.push_back(0);
    for(int i = 1; i < n; i++){
        if(s[i] == '0' && s[i-1] == '1')    v.push_back(i);
    }
    vector<int> onea(n, 1<<30), oneb(n, -1), zerob(n, -1);
    for(int i = 0; i < n; i++){
        if(s[i] == '1'){
            if(i)   onea[i] = min(onea[i-1], i);
            else    onea[i] = i;
        }
    }
    for(int i = n-1; i >= 0; i--){
        if(s[i] == '0'){
            if(i != n-1)    zerob[i] = max(zerob[i+1], i);
            else            zerob[i] = i;
        }
        if(s[i] == '1'){
            if(i != n-1)    oneb[i] = max(oneb[i+1], i);
            else            oneb[i] = i;
        }
    }
    if(v.size() <= k){
        cout << n << endl;
        return 0;
    }
    int vlen = v.size(), ans = 0;
    for(int i = 0; i <= vlen-k; i++){
        int j = i + k - 1;
        int l = v[i], r = zerob[v[j]];
        if(r+1 < n) r = oneb[r+1];
        if(l > 0)   l = onea[l-1];
        ans = max(ans, r-l+1);
    }
    cout << ans << endl;
    return 0;
}