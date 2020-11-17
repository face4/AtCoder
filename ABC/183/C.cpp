#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int t[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> t[i][j];
        }
    }
    vector<int> v(n);
    for(int i = 0; i < n; i++)  v[i] = i;
    int ans = 0;
    do{
        if(v[0])    break;
        int val = 0;
        for(int i = 0; i < n; i++)  val += t[v[(i+n-1)%n]][v[i]];
        ans += val==k;
    }while(next_permutation(v.begin(), v.end()));
    cout << ans << endl;
    return 0;
}