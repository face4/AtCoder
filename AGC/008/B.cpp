#include<iostream>
#include<climits>
using namespace std;

typedef long long ll;

int main(){
    int n, k;
    cin >> n >> k;

    ll a[n+2], b[n+2];
    a[0] = 0, b[0] = 0;

    int x;
    for(int i = 1; i <= n; i++){
        cin >> x;
        a[i] = a[i-1] + x;
        b[i] = b[i-1] + max(0, x);
    }
    b[n+1] = b[n];

    ll score = LLONG_MIN;
    for(int r = k; r <= n; r++){
        int l = r-k+1;
        ll center = max(0ll, a[r]-a[l-1]);
        ll lefthand = b[l-1] - b[0];
        ll righthand = b[n+1]-b[r];
        score = max(score, center+lefthand+righthand);
    }

    cout << score << endl;

    return 0;
}