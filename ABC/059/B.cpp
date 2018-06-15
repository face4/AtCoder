#include<iostream>
using namespace std;

int main(){
    string a, b;
    cin >> a >> b;

    if(a.length() < b.length()){
        cout << "LESS" << endl;
    }else if(a.length() > b.length()){
        cout << "GREATER" << endl;
    }else{
        int i;
        for(i = 0; i < a.length(); i++){
            if(a[i] != b[i]){
                if(a[i] > b[i]) cout << "GREATER" << endl;
                else            cout << "LESS" << endl;
                break;
            }
        }

        if(i == a.length())  cout << "EQUAL" << endl;
    }

    return 0;
}