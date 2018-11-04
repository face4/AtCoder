#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    int p[m], y[m];
    vector<int> pre[n+1];

    for(int i = 0; i < m; i++){
        cin >> p[i] >> y[i];
        pre[p[i]].push_back(y[i]);
    }

    for(int i = 1; i <= n; i++) sort(pre[i].begin(), pre[i].end());

    for(int i = 0; i < m; i++){
        int pos = (lower_bound(pre[p[i]].begin(), pre[p[i]].end(), y[i]) - pre[p[i]].begin())+1;
        cout << setw(6) << right << setfill('0') << p[i];
        cout << setw(6) << right << setfill('0') << pos << endl;
    }

    return 0;
}