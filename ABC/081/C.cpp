#include<iostream>
#include<algorithm>
#include<numeric>
using namespace std;

int main(){
    int n, k, a;
    cin >> n >> k;

    int x[n];
    for(int i = 0; i < n; i++)  x[i] = 0;
    for(int i = 0; i < n; i++){
        cin >> a;
        x[a-1]++;
    }

    sort(x, x+n);
    reverse(x, x+n);

    cout << accumulate(x+k, x+n, 0) << endl;

    return 0;
}