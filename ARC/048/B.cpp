#include<iostream>
using namespace std;

int memo[100001][3] = {};
int sum[100002] = {};
int r[100000], h[100000];

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> r[i] >> h[i];
        memo[r[i]][h[i]-1]++;
        sum[r[i]]++;
    }

    for(int i = 0; i < 100001; i++) sum[i+1] += sum[i];

    for(int i = 0; i < n; i++){
        cout << sum[r[i]-1]+memo[r[i]][(h[i])%3] << " " 
             << n-sum[r[i]]+memo[r[i]][(h[i]+1)%3] << " "
             << memo[r[i]][h[i]-1]-1 << endl;
    }

    return 0;
}