#include<iostream>
#include<algorithm>
using namespace std;

bool less_reverse(string x, string y){
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    return x < y;
}

int main(){
    int n;
    cin >> n;

    string s[n];
    for(int i = 0; i < n; i++)  cin >> s[i];
    sort(s, s+n, less_reverse);

    for(int i = 0; i < n; i++)  cout << s[i] << endl;

    return 0;
}