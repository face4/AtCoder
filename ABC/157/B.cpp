#include<iostream>
using namespace std;

int main(){
    int a[3][3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> a[i][j];
        }
    }
    int b[3][3] = {};
    int n;
    cin >> n;
    while(n--){
        int x;  cin >> x;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(a[i][j]==x)  b[i][j] = true;
            }
        }
    }
    bool ok = false;
    for(int i = 0; i < 3; i++){
        bool tmp = true;
        for(int j = 0; j < 3; j++)  tmp &= b[i][j];
        ok |= tmp;
        tmp = true;
        for(int j = 0; j < 3; j++)  tmp &= b[j][i];
        ok |= tmp;
    }
    bool tmp = true;
    for(int i = 0; i < 3; i++)  tmp &= b[i][i];
    ok |= tmp;
    tmp = true;
    for(int i = 0; i < 3; i++)  tmp &= b[i][2-i];
    ok |= tmp;
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}