#include<iostream>
#include<set>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    int a[n];
    set<int> s;
    vector<int> v;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        s.insert(a[i]);
    }

    for(int x : s){
        v.push_back(x);
    }
    
    for(int i = 0; i < n; i++){
        cout << (lower_bound(v.begin(), v.end(), a[i]) - v.begin()) << endl;
    }

    return 0;
}