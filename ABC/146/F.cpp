// 嘘貪欲っぽい
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n, m;
    string s;
    cin >> n >> m >> s;
    reverse(s.begin(),s.end());
    int acc = 0;
    for(int i = 1; i <= n; i++){
        if(s[i] == '1') acc++;
        else            acc = 0;
        if(acc >= m){
            cout << -1 << endl;
            return 0;
        }
    }
    vector<int> ret;
    vector<int> ok;
    for(int i = 0; i <= n; i++) if(s[i]=='0')   ok.push_back(i);
    int pos = 0;
    while(pos < n){
        int next = min(n, pos+m);
        next = *(--upper_bound(ok.begin(),ok.end(),next));
        ret.push_back(next-pos);
        pos = next;
    }
    reverse(ret.begin(), ret.end());
    for(int i = 0; i < ret.size(); i++) cout << ret[i] << " \n"[i+1==ret.size()];
    return 0;
}