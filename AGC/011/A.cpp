#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n, c, k;
    cin >> n >> c >> k;

    int T[n];
    for(int i = 0; i < n; i++)  cin >> T[i];
    sort(T, T+n);

    int cnt = 0, first = T[0], tmpcnt = 1;
    for(int i = 1; i < n; i++){
        if(tmpcnt < c && T[i] <= first+k){
            tmpcnt++;
        }else{
            cnt++;
            first = T[i];
            tmpcnt = 1;
        }
    }

    cnt++;

    cout << cnt << endl;

    return 0;
}