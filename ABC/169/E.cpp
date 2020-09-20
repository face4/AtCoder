#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++)  cin >> a[i] >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    double amid = n%2 ? a[n/2] : (a[n/2]+a[n/2-1])/2.0;
    double bmid = n%2 ? b[n/2] : (b[n/2]+b[n/2-1])/2.0;
    cout << (n%2 ? (int)(bmid-amid)+1 : (int)((bmid-amid)*2)+1) << endl;
    return 0;
}