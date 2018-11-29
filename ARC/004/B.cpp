#include<iostream>
#include<numeric>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i++)  cin >> a[i];

    cout << accumulate(a, a+n, 0) << endl << max(0, 2**max_element(a, a+n)-accumulate(a, a+n, 0)) << endl;

    return 0;
}