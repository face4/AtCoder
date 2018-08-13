#include<iostream>
#include<vector>
using namespace std;

int main(){
    string s;
    vector<vector<int>> v(26);
    int a = -2, b = -2;

    cin >> s;
    for(int i = 0; i < s.length(); i++){
        v[s[i]-'a'].push_back(i);
    }

    for(int i = 0; i < 26; i++){
        if(v[i].empty())    continue;
        for(int j = 0; j < v[i].size()-1; j++){
            if((v[i][j+1]-v[i][j]+1)/2 < 2){
                a = v[i][j], b = v[i][j+1];
            }
        }
    }

    cout << a+1 << " " << b+1 << endl;

    return 0;
}