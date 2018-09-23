#include<iostream>
#include<cstring>
using namespace std;
#define rep(i, a) for (int i = 0; i < (a); i++)

typedef long long ll;

ll dpa[20][2][2][2] = {};    // digit, less, four, nine
ll dpb[20][2][2][2] = {};    // digit, less, four, nine

int main(){
    string a, b;
    cin >> a >> b;
    
    a = to_string(stoll(a) - 1ll);

    int alen = a.length(), blen = b.length();

    dpa[0][0][0][0] = 1;
    rep (i, alen) rep (j, 2) rep (k,2) rep (l,2) {
        int lim = j ? 9 : a[i] - '0';
        rep(d, lim+1){
            dpa[i+1][j || d < lim][k || d == 4][l || d == 9] += dpa[i][j][k][l];
        }
    }

    dpb[0][0][0][0] = 1;
    rep (i, blen) rep (j, 2) rep (k,2) rep (l,2) {
        int lim = j ? 9 : b[i] - '0';
        rep(d, lim+1){
            dpb[i+1][j || d < lim][k || d == 4][l || d == 9] += dpb[i][j][k][l];
        }
    }

    ll afn = 0, bfn = 0;
    rep(j, 2) rep(k, 2) rep(l, 2){
        if(k || l)
            afn += dpa[alen][j][k][l], bfn += dpb[blen][j][k][l];
    }

    cout << bfn-afn << endl;
    
    return 0;
}