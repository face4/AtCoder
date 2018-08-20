#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int c;
    cin >> c;

    int ans[3] = {};
    for(int i = 0; i < c; i++){
        int a[3];
        for(int j = 0; j < 3; j++)  cin >> a[j];
        sort(a, a+3);
        for(int j = 0; j < 3; j++)  ans[j] = max(ans[j], a[j]);
    }
    
    cout << ans[0]*ans[1]*ans[2] << endl;

    return 0;
}
