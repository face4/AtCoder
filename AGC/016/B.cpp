// こういう問題が解けるようになる気がしない
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)  cin >> a[i];
    int k = *max_element(a.begin(), a.end());
    int l = *min_element(a.begin(), a.end());
    string ans;
    if(k-l > 1){
        ans = "No";
    }else if(k == l){
        ans = k == n-1 || 2*k <= n ? "Yes" : "No";
    }else{
        int lonely = 0;
        for(int i = 0; i < n; i++)  lonely += (a[i] == k-1);
        ans = lonely < k && 2*(k-lonely) <= n-lonely ? "Yes" : "No";
    }
    cout << ans << endl;
    return 0;
}
