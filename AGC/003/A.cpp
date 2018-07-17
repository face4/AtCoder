#include<iostream>
#include<set>
using namespace std;

int main(){
    char x;
    set<char> s;
    while(cin >> x) s.insert(x);

    if(s.size() == 4){
        cout << "Yes" << endl;
    }else if(s.size()%2 == 1){
        cout << "No" << endl;
    }else{
        if(s.count('S') && s.count('N'))    cout << "Yes" << endl;
        else if(s.count('W') && s.count('E'))    cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}