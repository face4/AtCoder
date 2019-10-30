#include<iostream>
#include<vector>
#include<set>
#include<queue>
using namespace std;
typedef long long ll;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> p(n), rev(n), sorted(n, 0);
    for(int i = 0; i < n; i++)  cin >> p[i], rev[p[i]] = i;
    for(int i = 1; i < n; i++){
        if(p[i-1] < p[i])   sorted[i] = 1;
        sorted[i] += sorted[i-1];
    }
    set<int> s;
    for(int i = 0; i < k; i++){
        s.insert(p[i]);
    }
    int ans = 0, flat = 0;
    if(sorted[k-1] == k-1)  flat++;
    else                    ans++;
    for(int i = 1; i <= n-k; i++){
        bool flag = (p[i-1] != *s.begin());
        s.erase(p[i-1]);
        s.insert(p[i+k-1]);
        flag |= (p[i+k-1] != *s.rbegin());
        if(sorted[i+k-1]-sorted[i] == k-1)  flat = 1;
        else if(flag)                       ans++;
    }
    cout << ans+flat << endl;
    return 0;
}