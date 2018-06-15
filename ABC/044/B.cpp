#include<iostream>
using namespace std;

int main(){
    int appearance[26] = {};

    string w;
    cin >> w;

    for(int i = 0; i < w.length(); i++){
        appearance[w[i]-'a']++;
    }

    for(int i = 0; i < 26; i++){
        if(appearance[i]&1){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}