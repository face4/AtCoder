#include<iostream>
using namespace std;

bool startsWith(string str, string pre){
    int s = str.length(), p = pre.length();
    if(s < p)   return false;

    int j;
    for(j = 0; j < p; j++){ 
        if(str[j] != pre[j])  break;
    }

    return j == p;
}

int main(){
    string s;
    cin >> s;

    if(startsWith(s, "MUJIN"))  cout << "Yes" << endl;
    else                        cout << "No" << endl;
    
    return 0;
}