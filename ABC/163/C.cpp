#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> ret(n, 0);
    for(int i = 1; i < n; i++){
        int x;  cin >> x;
        ret[--x]++;
    }
    for(int i = 0; i < n; i++)  cout << ret[i] << endl;
    return 0;
}