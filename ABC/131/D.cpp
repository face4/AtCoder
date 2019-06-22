#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> vp;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        vp.push_back({b,a});
    }
    sort(vp.begin(), vp.end());
    ll now = 0;
    for(int i = 0; i < n; i++){
        now += vp[i].second;
        if(now > vp[i].first){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}