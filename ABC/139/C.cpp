#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    int h[n];
    for(int i = 0; i < n; i++)  cin >> h[i];
    vector<int> ans(n, 0);
    for(int i = n-2; i >= 0; i--){
        if(h[i] >= h[i+1])  ans[i] = ans[i+1]+1;
    }
    cout << *max_element(ans.begin(), ans.end()) << endl;
    return 0;
}