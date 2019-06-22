#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<pair<string,int>,int>> vp;
    for(int i = 0; i < n; i++){
        string s;
        int p;
        cin >> s >> p;
        vp.push_back({{s,-p},i+1});
    }
    sort(vp.begin(), vp.end());
    for(auto p : vp)    cout << p.second << endl;
    return 0;
}