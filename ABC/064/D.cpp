#include<iostream>
using namespace std;

int main(){
    int n;
    string s;

    cin >> n >> s;

    int left = 0, right = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '('){
            right++;
        }else if(s[i] == ')'){
            left++;
            if(right > 0)  right--, left--;
        }
    }

    for(int i = 0; i < left; i++)   cout << '(';
    cout << s;
    for(int i = 0; i < right; i++)  cout << ')';
    cout << endl;

    return 0;
}