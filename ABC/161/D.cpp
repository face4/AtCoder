#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

vector<ll> v;

void dfs(ll val, int len){
    v.push_back(val);
    if(len == 10)   return;
    int i = val%10;
    for(int j = -1; j <= 1; j++){
        if(i+j < 0 || i+j > 9)  continue;
        dfs(val*10+i+j, len+1);
    }
}

int main(){
    int k;
    cin >> k;
    for(int i = 1; i <= 9; i++) dfs(i, 1);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    cout << v[k-1] << endl;
    return 0;
}