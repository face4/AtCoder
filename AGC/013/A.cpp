#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i++)  cin >> a[i];

    int ans = 0;
    int status = 0; // 0-first 1-ambiguous 2-ascending 3-descending
    for(int i = 0; i < n; i++){
        if(status == 0){
            status = 1;
            continue;
        }else if(status == 1){
            if(a[i-1] < a[i])       status = 2;
            else if(a[i-1] > a[i])  status = 3;
        }else if(status == 2){
            if(a[i-1] > a[i]){
                ans++;
                status = 1;
            }
        }else if(status == 3){
            if(a[i-1] < a[i]){
                ans++;
                status = 1;
            }
        }
    }
    ans++;

    cout << ans << endl;

    return 0;
}