#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;

    vector<ll> a(n+1);
    a[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    vector<ll> sum(n+1);
    sum[0] = 0;
    for(int i = 1; i <= n; i++){
        sum[i] = sum[i-1] + a[i];
    }

    int cnt = 0;
    for(int i = 1; i <= n; i++){
        ll body = a[i];
        int pos = i;
        bool ok = false;
        
        while(pos != n){
            body = sum[pos];
            auto next = upper_bound(a.begin(), a.end(), 2*body);
            int nextpos = --next - a.begin();
            if(pos == nextpos)  break;
            else                pos = nextpos;
        }

        if(pos == n)  cnt++;
    }

    cout << cnt << endl;

    return 0;
}