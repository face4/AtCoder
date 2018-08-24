#include<iostream>
#include<algorithm>
using namespace std;

bool ok(int a[8]){
    for(int i = 0; i < 7; i++){
        for(int j = i+1; j < 8; j++){
            if(abs(a[i]-a[j]) == abs(i-j))  return false;
        }
    }
    return true;
}

int main(){
    int pos[8] = {};
    string line;
    
    bool judge = true;

    for(int i = 0; i < 8; i++){
        cin >> line;
        pos[i] = -1;
        for(int j = 0; j < 8; j++){
            if(line[j] == 'Q'){
                if(pos[i] == -1)    pos[i] = j;
                else                judge = false;
            } 
        }
    }

    int a[8];
    for(int i = 0; i < 8; i++)  a[i] = i;

    bool found = false;
    do{
        if(ok(a)){
            bool match = true;
            for(int i = 0; i < 8; i++){
                if(pos[i] != -1 && pos[i] != a[i])  match = false;
            }
            if(match){
                found = true;
                break;
            }
        }
    }while(next_permutation(a, a+8));

    if(judge && found){
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(a[i] == j) cout << 'Q';
                else          cout << '.';
            }
            cout << endl;
        }
    }else{
        cout << "No Answer" << endl;
    }

    return 0;
}