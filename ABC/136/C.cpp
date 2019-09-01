#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i = 0; i < n; i++)  cin >> h[i];
    h[0]--;
    bool valid = true;
    for(int i = 1; i < n; i++){
        if(h[i] > h[i-1])    h[i]--;
        else if(h[i] < h[i-1])  valid = false;
    }
    cout << (valid ? "Yes" : "No") << endl;
    return 0;
}