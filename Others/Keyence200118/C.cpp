#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, k, s;
    cin >> n >> k >> s;
    vector<int> v;
    for(int i = 0; i < k; i++){
        v.push_back(s);
    }
    int res = 1e9;
    if(res == s)    res--;
    for(int i = 0; i < n-k; i++){
        v.push_back(res);
    }
    for(int i = 0; i < n; i++){
        cout << v[i] << " \n"[i==n];
    }
    return 0;
}