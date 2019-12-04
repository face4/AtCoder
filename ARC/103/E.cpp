#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.length();
    if(s[0] == '0' || s[n-1] == '1'){
        cout << -1 << endl;
        return 0;
    }
    for(int i = 0; i < (n-1)/2; i++){
        if(s[i] != s[n-2-i]){
            cout << -1 << endl;
            return 0;
        }
    }
    // 1.....10の形であることが保証される
    vector<int> ans;
    stack<int> un;
    un.push(0);
    for(int i = 1; i < n; i++){
        if(s[i] == '1'){
            while(!un.empty()){
                int x = un.top();   un.pop();
                ans.push_back(x); ans.push_back(i);
            }
        }
        un.push(i);
    }
    ans.push_back(n-2); ans.push_back(n-1);
    for(int i = 0; i < n-1; i++){
        cout << ans[2*i]+1 << " " << ans[2*i+1]+1 << endl;
    }
    return 0;
}