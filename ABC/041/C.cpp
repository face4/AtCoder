#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<pair<int,int>> v;
    int a;
    for(int i = 1; i <= n; i++){
        cin >> a;
        v.push_back({a,i});
    }

    sort(v.rbegin(), v.rend());
    for(pair<int,int> p : v)    cout << p.second << endl;

    return 0;
}