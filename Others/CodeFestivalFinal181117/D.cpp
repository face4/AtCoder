// 他人の提出を参考にしてmap,setではなく配列を使うようにした
#include<iostream>
#include<vector>
using namespace std;

int enc(char c){
    if(c <= 'Z')    return c - 'A';
    else            return c - 'a' + 26;
}

char dec(int x){
    if(x <= 25) return (char)('A' + x);
    else        return (char)('a' + x - 26);
}

int cnt[55][55][55] = {}, pos[55][55][55] = {};

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        vector<int> bef(52, 0), aft(52, 0);
        for(char c : s) aft[enc(c)]++;
        for(int j = 0; j < s.length(); j++){
            int num = enc(s[j]);
            aft[num]--;
            for(int k = 0; k < 52; k++){
                for(int l = 0; l < 52; l++){
                    if(bef[k] > 0 && aft[l] > 0 && i+1 > pos[k][num][l]){
                        cnt[k][num][l]++;
                        pos[k][num][l] = i+1;
                    }
                }
            }
            bef[num]++;
        }
    }
    int ma = 0;
    string ans;
    for(int i = 0; i < 55; i++){
        for(int j = 0; j < 55; j++){
            for(int k = 0; k < 55; k++){
                if(cnt[i][j][k] > ma){
                    ma = cnt[i][j][k];
                    string tmp = "";
                    tmp += dec(i);
                    tmp += dec(j);
                    tmp += dec(k);
                    ans = tmp;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
