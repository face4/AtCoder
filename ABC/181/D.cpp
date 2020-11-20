#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    string s;
    cin >> s;
    if(s.length() < 3){
        sort(s.begin(), s.end());
        do{
            if(stoi(s)%8 == 0){
                cout << "Yes" << endl;
                return 0;
            }
        }while(next_permutation(s.begin(), s.end()));
        cout << "No" << endl;
        return 0;
    }
    int cnt[10] = {};
    for(char c : s) cnt[c-'0']++;
    for(int i = 104; i < 1000; i += 8){
        int need[10] = {};
        int j = i;
        while(j > 0)    need[j%10]++, j /= 10;
        bool ok = true;
        for(j = 0; j < 10; j++) ok &= need[j] <= cnt[j];
        if(ok){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}