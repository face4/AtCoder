#include<iostream>
#include<vector>
using namespace std;

struct BIT{
    // 1-origin
    vector<int> v;
    int n;

    BIT(){}

    BIT(int _n):
        v(vector<int>(_n+1, 0)), n(_n) {}

    int sum(int i){
        int s = 0;
        while(i > 0){
            s += v[i];
            i -= lsb(i);
        }
        return s;
    }
    
    int sum(int l, int r){
        return sum(r) - sum(l-1);
    }

    void add(int i, int x){
        while(i <= n){
            v[i] += x;
            i += lsb(i);
        }
    }

private:
    // least significant bit
    int lsb(int i){
        return i & -i;
    }
};

int main(){
    int n;
    string s;
    int q;
    cin >> n >> s >> q;

    BIT bit[26];
    for(int i = 0; i < 26; i++) bit[i] = BIT(n);

    for(int i = 0; i < n; i++){
        bit[s[i]-'a'].add(i+1, 1);
    }

    while(q--){
        int op;
        cin >> op;
        if(op == 1){
            int i;
            char c;
            cin >> i >> c;
            i--;
            if(s[i] == c)   continue;
            bit[s[i]-'a'].add(i+1, -1);
            s[i] = c;
            bit[s[i]-'a'].add(i+1, 1);
        }else if(op == 2){
            int l, r;
            cin >> l >> r;
            int cnt = 0;
            for(int i = 0; i < 26; i++){
                cnt += (bit[i].sum(r)-bit[i].sum(l-1))>0;
            }
            cout << cnt << endl;
        }
    }
    return 0;
}