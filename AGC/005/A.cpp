#include<iostream>
using namespace std;

int main(){
    string x;
    cin >> x;

    int scnt = 0;
    int cut = 0;
    for(int i = 0; i < x.length(); i++){
        if(x[i] == 'S'){
            scnt++;
        }else if(x[i] == 'T' && scnt > 0){
            scnt--;
            cut++;
        }
    }

    cout << x.length() - cut*2 << endl;
    return 0;
}