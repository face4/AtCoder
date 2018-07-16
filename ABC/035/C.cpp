#include<iostream>
using namespace std;

int l[200001] = {};
int r[200001] = {};

int main(){
    int n, q;
    cin >> n >> q;

    int x, y;
    for(int i = 0; i < q; i++){
        cin >> x >> y;
        l[x]++;
        r[y]++;
    }

    int cnt = 0;
    
    for(int i = 1; i <= n; i++){
        cnt += l[i];
        cout << cnt%2;
        cnt -= r[i];
    }

    cout << endl;

    return 0;
}