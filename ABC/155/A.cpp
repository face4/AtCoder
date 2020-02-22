#include<iostream>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    int cnt[10] = {};
    cnt[a]++, cnt[b]++, cnt[c]++;
    int two = 0, one = 0;
    for(int i = 0; i < 10; i++){
        if(cnt[i]==2)   two++;
        else if(cnt[i]==1)  one++;
    }
    cout << (two==1&&one==1 ? "Yes" : "No") << endl;
    return 0;
}
