#include<iostream>
using namespace std;

int main(){
    int a;
    string s;

    cin >> a >> s;
    bool judge = (a == 0);

    for(int i = 0; i < s.length(); i++){
        if(s[i] == '+'){
            a++;
        }else if(s[i] == '-'){
            a--;
        }
        if(a == 0)  judge = true;
    }

    if(judge)   cout << "Yes" << endl;
    else        cout << "No" << endl;
    
    return 0;
}