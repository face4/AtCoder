#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int v[n], c[n];
    for(int i = 0; i < n; i++)  cin >> v[i];
    for(int i = 0; i < n; i++)  cin >> c[i];
    int sum = 0;
    for(int i = 0; i < n; i++)  sum += max(0, v[i]-c[i]);
    cout << sum << endl;
    return 0;
}