// 2,3の倍数のみ使うという部分までは考察したが
// そこから詰めることが出来ず、結局解説を読んだ
#include<iostream>
#include<set>
using namespace std;

int main(){
    int n;
    cin >> n;
    if(n < 6){
        int ans[5] = {2, 63, 5, 20, 30};
        for(int i = 0; i < n; i++)  cout << ans[i] << " \n"[i+1==n];
        return 0;
    }
    set<int> ans;
    int cnt[4] = {}, add[4] = {2, 3, 4, 6}, sum = 0;
    for(int i = 0; i < n; i++){
        ans.insert(6*cnt[i%4]+add[i%4]);
        cnt[i%4]++;
        sum = (sum+add[i%4])%6;
    }
    if(sum == 2){
        ans.erase(8);
        ans.insert(6*cnt[3]+6);
    }else if(sum == 3){
        ans.erase(9);
        ans.insert(6*cnt[3]+6);
    }else if(sum == 5){
        ans.erase(9);
        ans.insert(6*cnt[2]+4);
    }
    for(auto it = ans.begin(); it != ans.end();){
        cout << *it;
        it++;
        if(it != ans.end()) cout << " ";
    }
    cout << endl;
    return 0;
}
