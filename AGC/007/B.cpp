#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++)  a[i] = (n+1)*(i+1);
    for(int i = 0; i < n; i++)  b[i] = (n+1)*(n-i);
    vector<int> r(n);
    for(int i = 0; i < n; i++){
        int x;  cin >> x;
        r[x-1] = i+1;
    }
    for(int i = 0; i < n; i++)  cout << a[i] << " \n"[i+1==n];
    for(int i = 0; i < n; i++)  cout << b[i]+r[i] << " \n"[i+1==n];
    return 0;
}