#include<iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int a[n], sum = 0;
    for(int i = 0; i < n; i++)  cin >> a[i], sum += a[i];
    double d = sum/4.0/m;
    int ch = 0;
    for(int i = 0; i < n; i++)  ch += a[i] >= d;
    cout << (ch >= m ? "Yes" : "No") << endl;
    return 0;
}