#include<iostream>
#include<vector>
using namespace std;

// Aの個数、Bの個数はmod3で同一視しても良い(?)
// mod3で同一視した上で個数を一致させれば良い
// 並べ替えが自由に出来ることが実験からわかるので、位置については考えなくてよい
// AB -> AAA -> BBAA -> BAAAA -> BA という操作が出来るので.

int main(){
    string s, t;
    cin >> s >> t;
    int slen = s.length()+1, tlen = t.length()+1;
    vector<int> ssum(slen, 0), tsum(tlen, 0);
    for(int i = 1; i < slen; i++) ssum[i] = ssum[i-1]+(s[i-1]=='A');
    for(int i = 1; i < tlen; i++) tsum[i] = tsum[i-1]+(t[i-1]=='A');
    
    bool wf[9][9] = {};
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            wf[i*3+j][(i+2)%3*3+(j+2)%3] = true;
        }
    }

    for(int k = 0; k < 9; k++){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(wf[i][k] && wf[k][j])    wf[i][j] = true;
            }
        }
    }

    int q;
    cin >> q;
    while(q-- > 0){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int sa = ssum[b]-ssum[a-1];
        int sb = b-a+1-sa;
        int ta = tsum[d]-tsum[c-1];
        int tb = d-c+1-ta;
        sa %= 3, sb %= 3, ta %= 3, tb %= 3;
        cout << (wf[sa*3+sb][ta*3+tb] ? "YES" : "NO") << endl;
    }
    return 0;
}