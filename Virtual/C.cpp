#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct data{
    string s;
    int id;
    bool operator<(const data other) const{
        return s < other.s;
    }
};

int main(){
    int n, k;
    cin >> n >> k;

    bool flag[100001] = {};
    int a;
    for(int i = 0; i < k; i++){
        cin >> a;
        flag[a] = true;
    }

    vector<string> v(n), c;
    string shortest = "";
    int slen = 100001;
    for(int i = 1; i <= n; i++){
        cin >> v[i-1];
        if(flag[i]){
            c.push_back(v[i-1]);
            if(v[i-1].length() < slen){
                shortest = v[i-1];
                slen = v[i-1].length();
            }
        }
    }
    sort(v.begin(), v.end());
    sort(c.begin(), c.end());

    string ans = "";
    int pos = 0;

    while(upper_bound(c.begin(), c.end(), ans+"{")-lower_bound(c.begin(), c.end(), ans) == k){
        if(upper_bound(v.begin(), v.end(), ans+"{")-lower_bound(v.begin(), v.end(), ans) == k){
            cout << ans << endl;
            return 0;
        }
        if(pos == shortest.length())    break;
        ans += shortest[pos++];
    }

    cout << -1 << endl;

    return 0;
}