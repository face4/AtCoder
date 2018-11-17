#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

int n, h;
int ans = 0;
int a[10] = {};

void dfs(){
    if(accumulate(a, a+n, 0) == 0){
        ans++;
        return;
    }

    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += a[i];
        if(sum == 0 || a[i] == 0)    continue;
        if(sum <= h){
            int tmp = a[i];
            a[i] = 0;
            dfs();
            a[i] = tmp;
        }
    }
}

int main(){
    cin >> n >> h;
    for(int i = 0; i < n; i++)  cin >> a[i];
    dfs();
    cout << ans << endl;
    return 0;
}