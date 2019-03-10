#include<iostream>
#include<stack>
using namespace std;

int main(){
    string s;
    cin >> s;
    stack<char> st;
    int ans = 0;
    for(char c : s){
        if(!st.empty() && c != st.top()){
            st.pop();
            ans += 2;
        }else{
            st.push(c);
        }
    }
    cout << ans << endl;
    return 0;
}