#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        int x;  cin >> x;
        v[x-1] = i;
    }
    for(int i = 0; i < n; i++)  cout << v[i]+1 << " \n"[i+1==n];
    return 0;
}