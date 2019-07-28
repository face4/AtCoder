#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n+1, 0);
    for(int i = 1; i <= n; i++)  cin >> v[i];
    vector<bool> ans(n+1, 0);
    for(int i = n; i >= n/2+1; i--){
        if(v[i] == 1)   ans[i] = true;
    }
    for(int i = n/2; i >= 1; i--){
        int cnt = 0;
        for(int j = i+i; j <= n; j+=i)   cnt += ans[j];
        if(cnt%2 != v[i]%2) ans[i] = true;
    }
    vector<int> ret;
    for(int i = 1; i <= n; i++) if(ans[i])  ret.push_back(i);
    cout << ret.size() << endl;
    for(int i = 0; i < ret.size(); i++) cout << ret[i] << " \n"[i+1==ret.size()];
    return 0;
}