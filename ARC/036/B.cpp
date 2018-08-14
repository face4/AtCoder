#include<iostream>
using namespace std;

int n;
int h[300000] = {}, l[300000] = {} , r[300000] = {};

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)  cin >> h[i];

    for(int i = 1; i < n; i++){
        if(h[i-1] < h[i])   l[i] = l[i-1]+1;
    }
    for(int i = n-2; i >= 0; i--){
        if(h[i] > h[i+1])   r[i] = r[i+1]+1;
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans, l[i] + r[i] + 1);
    }

    cout << ans << endl;

    return 0;
}