#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    // ストレートな座圧で解く
    int n;
    cin >> n;

    int a[n];
    vector<int> v;
    for(int i = 0; i < n; i++)  cin >> a[i], v.push_back(a[i]);

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for(int i = 0; i < n; i++){
        cout << distance(v.begin(), lower_bound(v.begin(), v.end(), a[i])) << endl;
    }
    
    // int n;
    // cin >> n;

    // int a[n];
    // set<int> s;
    // vector<int> v;

    // for(int i = 0; i < n; i++){
    //     cin >> a[i];
    //     s.insert(a[i]);
    // }

    // for(int x : s){
    //     v.push_back(x);
    // }
    
    // for(int i = 0; i < n; i++){
    //     cout << (lower_bound(v.begin(), v.end(), a[i]) - v.begin()) << endl;
    // }

    return 0;
}