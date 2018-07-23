#include<iostream>
#include<set>
using namespace std;

int main(){
    string s, t;
    cin >> s >> t;

    // この部分を除くとREになる.
    // 正直何故これが必要なのかわからない.
    // 恐らくforループのindex-iが絡んでいる.
    if(s.length() < t.length()){
        cout << "UNRESTORABLE" << endl;
        return 0;
    }

    set<string> candidates;

    for(int i = 0; i <= s.length()-t.length(); i++){
        int j;
        for(j = 0; j < t.length(); j++){
            if(s[i+j] == '?' || s[i+j] == t[j]) continue;
            else    break;
        }

        if(j == t.length()){
            string tmp = s;
            for(j = 0; j < t.length(); j++) tmp[i+j] = t[j];
            for(j = 0; j < s.length(); j++) if(tmp[j] == '?')   tmp[j] = 'a';
            candidates.insert(tmp);
        }
    }

    if(candidates.size() > 0){
        cout << *candidates.begin() << endl;
    }else{
        cout << "UNRESTORABLE" << endl;
    }

    return 0;
}