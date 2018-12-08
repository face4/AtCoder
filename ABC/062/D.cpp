#include<iostream>
#include<numeric>
#include<set>
#include<climits>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;

    int a[3*n];
    for(int i = 0; i < 3*n; i++)    cin >> a[i];

    ll bef[n+1], aft[n+1];
    ll sum = accumulate(a, a+n, 0ll);
    bef[0] = sum;
    
    multiset<int> s;
    for(int i = 0; i < n; i++)  s.emplace(a[i]);
    multiset<int>::iterator it = s.begin();

    for(int i = n; i < 2*n; i++){
        s.emplace(a[i]);
        if(a[i] >= (*it)){
            sum += a[i]-(*it);
            it++;
        }
        bef[i-n+1] = sum;
    }

    s.clear();
    for(int i = 0; i < n; i++)  s.emplace(a[3*n-1-i]);
    it = s.end(); it--;
    sum = accumulate(a+2*n, a+3*n, 0ll);
    aft[n] = sum;

    for(int i = 2*n-1; i >= n; i--){
        s.emplace(a[i]);
        if(a[i] < (*it)){
            sum += a[i]-(*it);
            it--;
        }
        aft[i-n] = sum;
    }

    ll ans = LLONG_MIN;
    for(int i = 0; i < n+1; i++){
        ans = max(ans, bef[i]-aft[i]);
    }

    cout << ans << endl;
    
    return 0;
}