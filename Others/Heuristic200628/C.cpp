#include<iostream>
#include<set>
using namespace std;
typedef long long ll;

int main(){
    int d;
    cin >> d;
    int c[27];
    for(int i = 1; i <= 26; i++) cin >> c[i];
    int s[d+1][27];
    for(int i = 1; i <= d; i++){
        for(int j = 1; j <= 26; j++){
            cin >> s[i][j];
        }
    }
    set<int> h[27];
    for(int i = 1; i <= 26; i++) h[i].insert(0), h[i].insert(d+1);
    int t[d+1];
    int last[27] = {};
    ll now = 0;
    for(int i = 1; i <= d; i++){
        cin >> t[i];
        h[t[i]].insert(i);
        now += s[i][t[i]];
        last[t[i]] = i;
        ll dec = 0;
        for(int j = 1; j <= 26; j++)    dec += c[j]*(i-last[j]);
        now -= dec;
    }
    
    int m;
    cin >> m;
    while(m--){
        int d, q;
        cin >> d >> q;
        int bef = t[d];
        now -= s[d][bef];
        h[bef].erase(d);
        {
            int from = *(--h[bef].lower_bound(d));
            int to = *(h[bef].lower_bound(d));
            now -= (ll)c[bef]*(to-d)*(d-from);
        }
        t[d] = q;
        now += s[d][q];
        h[q].insert(d);
        {
            int from = *(--h[q].lower_bound(d));
            int to = *(h[q].upper_bound(d));
            now += (ll)c[q]*(to-d)*(d-from);
        }
        cout << now << endl;
    }
    return 0;
}