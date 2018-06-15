#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<string> l;

    int n, L;
    cin >> n >> L;

    string s;
    for(int i = 0; i < n; i++){
        cin >> s;
        l.push_back(s);
    }

    sort(l.begin(), l.end());

    for(string x : l)   cout << x;
    cout << endl;

    return 0;
}