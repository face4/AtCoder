#include<iostream>
#include<numeric>
using namespace std;

int main(){
    int n, l;
    cin >> n >> l;
    int a[n];
    for(int i = 0; i < n; i++)  a[i] = l + i;
    int sum = accumulate(a, a+n, 0);
    int ans, ma = 1<<30;
    for(int i = 0; i < n; i++){
        int tmp = sum - a[i];
        if(abs(tmp-sum) < ma){
            ma = abs(tmp-sum);
            ans = tmp;
        }
    }
    cout << ans << endl;
    return 0;
}