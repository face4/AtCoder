#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.length();
    auto f = [](char c)->bool{
        return c == 'A' || c == 'C' || c == 'G' || c == 'T';
    };
    int ans = 0;
    for(int i = 0; i < n; i++){
        int j = i;
        while(j < n && f(s[j])) j++;
        ans = max(ans, j-i);
    }
    cout << ans << endl;
    return 0;
}