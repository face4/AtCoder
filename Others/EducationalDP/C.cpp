#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;

    int ans[3] = {};
    int a[3];
    cin >> a[0] >> a[1] >> a[2];

    for(int i = 1; i < n; i++){
        int b[3], c[3] = {};
        cin >> b[0] >> b[1] >> b[2];
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                if(j == k)  continue;
                c[k] = max(c[k], a[j]+b[k]);
            }
        }
        for(int j = 0; j < 3; j++)  a[j] = c[j];
    }

    cout << max({a[0], a[1], a[2]}) << endl;
    return 0;
}