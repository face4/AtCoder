#include<iostream>
using namespace std;

int main(){
    int n, m, c;
    cin >> n >> m >> c;
    int b[m];
    for(int i = 0; i < m; i++)  cin >> b[i];
    int ans = 0;
    for(int i = 0; i < n; i++){
        int tmp = c;
        for(int j = 0; j < m; j++){
            int a;  cin >> a;
            tmp += a*b[j];
        }
        ans += (tmp > 0);
    }
    cout << ans << endl;
    return 0;
}