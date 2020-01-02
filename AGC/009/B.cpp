#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> v[100000];
int n;

int dfs(int x){
    vector<int> tmp;
    for(int j : v[x])   tmp.push_back(dfs(j));
    sort(tmp.rbegin(), tmp.rend());
    int ret = 0;
    for(int i = 0; i < tmp.size(); i++){
        ret = max(ret, tmp[i]+i+1);
    }
    return ret;
}

int main(){
    cin >> n;
    for(int i = 1; i < n; i++){
        int x;  cin >> x;
        v[--x].push_back(i);
    }
    cout << dfs(0) << endl;
    return 0;
}