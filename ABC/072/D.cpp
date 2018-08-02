#include<iostream>
using namespace std;

int n;
int p[100000];

int main(){
    cin >> n;

    for(int i = 0; i < n; i++)  cin >> p[i];

    int ans = 0, accum = 0;
    for(int i = 0; i < n-1; i++){
        if(i+1 == p[i]){
            ans++;
            swap(p[i], p[i+1]);
        }
    }
    if(n == p[n-1]){
        ans++;
        swap(p[n-2], p[n-1]);
    }

    cout << ans << endl;

    return 0;
}