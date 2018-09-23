#include<iostream>
using namespace std;

int s[100000], t[100000], c[100000];
int tim[200002], sum[200002] = {};

int main(){
    int n, C;
    cin >> n >> C;

    for(int i = 0; i < n; i++){
        cin >> s[i] >> t[i] >> c[i];
    }

    for(int i = 1; i <= C; i++){
        for(int j = 0; j < 200002; j++) tim[j] = 0;
        for(int j = 0; j < n; j++)  if(c[j] == i)   tim[s[j]*2-1]++, tim[t[j]*2]--;
        for(int j = 1; j < 200002; j++) tim[j] += tim[j-1];
        for(int j = 0; j < 200002; j++) if(tim[j] > 0)  sum[j]++;
    }
    int ans = 0;
    for(int i = 0; i < 200002; i++) ans = max(ans, sum[i]);
    cout << ans << endl;

    return 0;
}