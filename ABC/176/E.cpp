#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main(){
    int h, w, m;
    cin >> h >> w >> m;
    vector<int> v[h], count(w, 0);
    while(m--){
        int a, b;
        cin >> a >> b;
        a--, b--;
        v[a].push_back(b);
        count[b]++;
    }
    multiset<int> ms;
    ms.insert(0);
    for(int i = 0; i < w; i++)  if(count[i])    ms.insert(count[i]);
    int ans = 0;
    for(int i = 0; i < h; i++){
        for(int j : v[i])   ms.erase(ms.find(count[j])), ms.insert(count[j]-1);
        ans = max(ans, (int)v[i].size() + *ms.rbegin());
        for(int j : v[i])   ms.erase(ms.find(count[j]-1)), ms.insert(count[j]);
    }
    cout << ans << endl;
    return 0;
}