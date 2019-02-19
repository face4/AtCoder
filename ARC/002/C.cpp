#include<iostream>
using namespace std;

string op[4] = {"A", "B", "X", "Y"};

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans = n;
    for(int i = 0; i < 4; i++)for(int j = 0; j < 4; j++){
        for(int k = 0; k < 4; k++)for(int l = 0; l < 4; l++){
            string a = op[i]+op[j], b = op[k]+op[l];
            int tmp = 0;
            for(int cur = 0; cur < n; cur++){
                if(cur != n-1 && a == s.substr(cur,2) || b == s.substr(cur,2)){
                    cur++;
                }
                tmp++;
            }
            ans = min(ans, tmp);
        }
    }

    cout << ans << endl;
    
    return 0;
}