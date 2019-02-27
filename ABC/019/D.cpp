#include<iostream>
using namespace std;

int ask(int a, int b){
    cout << "? " << a << " " << b << endl << flush;
    int ret;
    cin >> ret;
    return ret;
}

int answer(int a){
    cout << "! " << a << endl << flush;
}

int main(){
    int n;
    cin >> n;
    int a = -1, score = 0;
    for(int i = 2; i <= n; i++){
        int d = ask(1, i);
        if(d > score){
            score = d, a = i;
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(i == a)  continue;
        ans = max(ans, ask(i, a));
    }
    answer(ans);
    return 0;
}