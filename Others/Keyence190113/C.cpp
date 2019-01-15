#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    ll as = 0, bs = 0;
    for(int i = 0; i < n; i++)  cin >> a[i], as += a[i];
    for(int i = 0; i < n; i++)  cin >> b[i], bs += b[i];

    if(as < bs){
        cout << -1 << endl;
        return 0;
    }

    int ans = 0;
    ll need = 0;
    vector<int> excess;

    for(int i = 0; i < n; i++){
        if(a[i] > b[i]){
            excess.push_back(a[i]-b[i]);
        }else if(a[i] < b[i]){
            ans++;
            need += b[i]-a[i];
        }
    }

    sort(excess.rbegin(), excess.rend());

    int cur = 0;
    while(need > 0){
        need -= excess[cur++];
    }

    cout << ans+cur << endl;

    return 0;
}