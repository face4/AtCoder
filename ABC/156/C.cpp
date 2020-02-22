#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int ret = 1<<30;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= 100; i++){
        int tmp = 0;
        for(int j = 0; j < n; j++){
            tmp += (a[j]-i)*(a[j]-i);
        }
        ret = min(ret, tmp);
    }
    cout << ret << endl;
    return 0;
}