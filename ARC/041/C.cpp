// 自力AC
#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;

void f(ll &ans, vector<int>& l, vector<int>& r){
    int pivr, pivl;
    if(r.size() >= l.size()){
        pivl = *l.begin();
        pivr = pivl-1;
    }else{
        pivr = *r.rbegin();
        pivl = pivr+1;
    }
    for(int j : r)   ans += pivr-j;
    for(int j : l)   ans += j-pivl;
    ll rsiz = r.size(), lsiz = l.size();
    ans -= rsiz*(rsiz-1)/2;
    ans -= lsiz*(lsiz-1)/2;
    r.clear();
    l.clear();
}

int main(){
    int n, l;
    cin >> n >> l;
    int leftmost = 1;
    ll ans = 0;
    int flag = 0;
    vector<int> accr, accl;
    for(int i = 0; i < n; i++){
        char c;
        int d;
        cin >> d >> c;
        if(c == 'L'){
            if(flag == 0){
                ans += d-leftmost;
                leftmost++;
            }else if(flag == 1){
                flag = 2;
            }
            if(flag == 2){
                accl.push_back(d);
            }
        }else if(c == 'R'){
            if(flag == 0){
                flag = 1;
            }
            if(flag == 1){
                accr.push_back(d);
            }else if(flag == 2){
                f(ans, accl, accr);
                accr.push_back(d);
                flag = 1;
            }
        }
    }
    if(flag == 1){
        accl.push_back(l+1);
    }
    if(flag){
        f(ans, accl, accr);
    }
    cout << ans << endl;
    return 0;
}
