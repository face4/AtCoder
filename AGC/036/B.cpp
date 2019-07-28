#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;
typedef long long ll;

int n;
ll k;
vector<int> a, pos[200001];

int main(){
    cin >> n >> k;
    a.resize(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
        pos[a[i]].push_back(i);
    }

    vector<int> ind;

    int start = 0;
    bool flag = true;
    vector<bool> used(n, 0);
    used[0] = true;

    while(flag){
        while(start < n){
            auto it = upper_bound(pos[a[start]].begin(), pos[a[start]].end(), start);
            if(it != pos[a[start]].end()){
                start = *it+1;
            }else{
                break;
            }
        }
        if(start == n){
            ind.push_back(-1);
            break;
        }else{
            ind.push_back(start);
            used[start] = true;
            if(pos[a[start]][0] != start){
                start = pos[a[start]][0]+1;
            }else{
                start++;
            }
        }
        if(used[start]){
            ind.push_back(-1);
            break;
        }  
    }

    int len = ind.size();
    k--;
    k %= len;
    start = ind[k];
    
    if(start == -1){
        cout << endl;
        return 0;
    }

    vector<int> res;
    while(start < n){
        auto it = upper_bound(pos[a[start]].begin(), pos[a[start]].end(), start);
        if(it != pos[a[start]].end()){
            start = *it+1;
        }else{
            res.push_back(a[start]);
            start++;
        }
    }

    for(int i = 0; i < res.size(); i++) cout << res[i] << " \n"[i+1==res.size()];
    return 0;
}