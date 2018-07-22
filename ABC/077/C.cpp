#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;

    vector<int> a(n), b(n), c(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    ll accum = 0;
    for(int i = 0; i < n; i++){
        accum += (lower_bound(a.begin(), a.end(), b[i]) - a.begin())* 
                    (c.end() - upper_bound(c.begin(), c.end(), b[i]));
    }

    cout << accum << endl;
    return 0;
}