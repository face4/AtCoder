#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

struct data{
    int a, b;
    bool operator<(const data other) const{
        return a < other.a;
    }
};

int main(){
    int n;
    cin >> n;

    vector<data> v(n);
    int a, b;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        v[i] = data({a, b});
    }

    sort(v.begin(), v.end());

    int m;
    cin >> m;

    int t;
    for(int i = 0; i < m; i++){
        cin >> t;
        auto it = upper_bound(v.begin(), v.end(), data({t,0}));
        int ans = INT_MAX;
        if(it != v.end())   ans = (*it).b;
        if(it != v.begin()){
            it--;
            ans = min(ans, (*it).b + t-(*it).a);
        }
        cout << ans << endl;
    }

    return 0;
}