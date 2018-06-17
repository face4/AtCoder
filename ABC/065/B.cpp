#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int a[n+1] = {};
    for(int i = 1; i <= n; i++)  cin >> a[i];
    
    bool b[n+1] = {};

    int cnt = 0, blight = 1;
    bool loop = false;
    while(blight != 2 && !loop){
        cnt++;
        b[blight] = true;
        blight = a[blight];
        if(b[blight])    loop = true;
    }

    if(loop)    cout << -1 << endl;
    else        cout << cnt << endl;

    return 0;
}