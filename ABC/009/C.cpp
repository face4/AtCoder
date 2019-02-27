#include<iostream>
#include<set>
using namespace std;

int main(){
    int n, k;
    string s;
    cin >> n >> k >> s;
    multiset<char> sc;
    for(char c : s) sc.insert(c);
    for(int i = 0; i < n; i++){
        for(auto it = sc.begin(); it != sc.end(); it++){
            multiset<char> cp = sc;
            cp.erase(cp.find(*it));
            for(int j = i+1; j < n; j++){
                auto x = cp.find(s[j]);
                if(x != cp.end())   cp.erase(x);
            }
            if(cp.size()+((*it) != s[i]) <= k){
                cout << *it;
                if((*it) != s[i])   k--;
                sc.erase(it);
                break;
            }
        }
    }
    cout << endl;
    return 0;
}