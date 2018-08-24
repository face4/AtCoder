#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    map<int,int> b;
    int c;
    for(int i = 0; i < 10; i++){
        cin >> c;
        b[c] = i;
    }

    int n;
    cin >> n;

    map<int,string> rev;
    vector<int> res;
    string s;

    for(int i = 0; i < n; i++){
        cin >> s;
        int tmp = 0;
        for(int i = 0; i < s.length(); i++){
            tmp = 10*tmp + b[s[i]-'0'];
        }
        res.push_back(tmp);
        rev[tmp] = s;
    }

    sort(res.begin(), res.end());

    for(int x : res)    cout << rev[x] << endl;

    return 0;
}