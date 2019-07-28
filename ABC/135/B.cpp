#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int p[n];
    for(int i = 0; i < n; i++)  cin >> p[i];
    int cnt = 0;
    for(int i = 0; i < n; i++)  cnt += (p[i]-1 != i);
    if(cnt <= 2)    cout << "YES" << endl;
    else            cout << "NO" << endl;
    return 0;
}