#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main(){
    string s;
    cin >> s;
    int n = s.length();
    vector<ll> ans(n+1, 0);
    vector<pair<int,pii>> vp;
    int pos = 0;
    while(pos < n){
        int npos = pos;
        while(npos < n && s[npos] == s[pos])    npos++;
        pii p;
        if(s[pos] == '<')   p = {pos, npos};
        else                p = {npos, pos};
        vp.push_back({npos-pos, p});
        pos = npos;
    }
    sort(vp.rbegin(), vp.rend());
    for(auto p : vp){
        int from = p.second.first, to = p.second.second;
        if(from < to){
            for(int i = 0; i+from <= to; i++)   ans[from+i] = max(ans[from+i], (ll)i);
        }else{
            for(int i = 0; from+i >= to; i--)   ans[from+i] = max(ans[from+i], -(ll)i);
        }
    }
    cout << accumulate(ans.begin(),ans.end(),0ll) << endl;
    return 0;
}