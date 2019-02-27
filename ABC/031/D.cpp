#include<iostream>
#include<vector>
using namespace std;

int k, n;
vector<int> len;
vector<string> v, s;

void dfs(int i){
    if(i == k){
        vector<string> ans(k, "");
        for(int j = 0; j < n; j++){
            int tmplen = 0;
            for(char x : v[j])  tmplen += len[x-'1'];
            if(tmplen != s[j].length()) return;
            tmplen = 0;
            for(char x : v[j]){
                string f = s[j].substr(tmplen, len[x-'1']);
                if(ans[x-'1'] == f || ans[x-'1'] == ""){
                    ans[x-'1'] = f;
                }else{
                    return;
                }
                tmplen += len[x-'1'];
            }
        }
        for(int j = 0; j < k; j++){
            cout << ans[j] << endl;
        }
        exit(0);
    }
    for(int j = 1; j <= 3; j++){
        len.push_back(j);
        dfs(i+1);
        len.pop_back();
    }
}

int main(){
    cin >> k >> n;
    v.resize(n);
    s.resize(n);
    for(int i = 0; i < n; i++){
        cin >> v[i] >> s[i];
    }
    dfs(0);
    return 0;
}