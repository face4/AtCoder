#include<iostream>
using namespace std;

bool contains(string str, string pre){
    int s = str.length(), p = pre.length();
    if(s < p)   return false;

    for(int i = 0; i <= s - p; i++){
        int j;
        for(j = 0; j < p; j++){ 
            if(str[i+j] != pre[j])  break;
        }
        if(j == p)  return true;
    }

    return false;
}

int main(){
    string s, t;
    cin >> s >> t;
    t += t;
    if(contains(t, s))  cout << "Yes" << endl;
    else                cout << "No" << endl;
    return 0;
}