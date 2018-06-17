#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n, k, x;
    cin >> n >> k;

    vector<int> l;
    for(int i = 0; i < n; i++){
        cin >> x;
        l.push_back(x);
    }

    sort(l.rbegin(), l.rend());
    int sum = 0;
    for(int i = 0; i < k; i++)  sum += l[i];

    cout << sum << endl;
    return 0;
}