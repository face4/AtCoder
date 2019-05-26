#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int h[n];
    for(int i = 0; i < n; i++)  cin >> h[i];
    int ans = 0;
    for(int i = 0; i < n; i++){
        bool judge = true;
        for(int j = 0; j < i; j++)  judge &= h[j] <= h[i];
        if(judge)   ans++;
    }
    cout << ans << endl;
    return 0;
}