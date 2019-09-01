#include<iostream>
#include<vector>
using namespace std;

int main(){
    int k, x;
    cin >> x >> k;
    vector<int> ans;
    for(int i = max(-1000000, k-x+1); i <= min(1000000, k+x-1); i++){
        ans.push_back(i);
    }
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " \n"[i+1==ans.size()];
    }
    return 0;
}