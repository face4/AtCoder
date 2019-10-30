// 自力AC
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int main(){
    int n, k, q;
    cin >> n >> k >> q;
    set<int> all;
    vector<int> a(n);
    for(int i = 0; i < n; i++)  cin >> a[i], all.insert(a[i]);
    all.insert(0);
    int ans = 1<<30;
    for(int piv : all){
        multiset<int> res, tmp;
        for(int i = 0; i <= n; i++){
            if(i == n || a[i] <= piv){
                while(tmp.size() >= k)  res.insert(*tmp.begin()), tmp.erase(tmp.begin());
                tmp.clear();
            }else{
                tmp.insert(a[i]);
            }
        }
        if(res.size() >= q){
            auto it = res.begin();
            int low = *it;
            for(int i = 0; i < q-1; i++)    it++;
            ans = min(ans, *it-low);   
        }
    }
    cout << ans << endl;
}
