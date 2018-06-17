#include<iostream>
#include<set>
using namespace std;

int main(){
    string s;
    int k;
    cin >> s >> k;

    if(k > s.length()){
        cout << 0 << endl;
    }else{
        set<string> keys;
        for(int i = 0; i <= s.length()-k; i++){
            keys.insert(s.substr(i, k));
        }
        cout << keys.size() << endl;
    }

    return 0;
}