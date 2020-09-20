#include<iostream>
using namespace std;

int main(){
    int x, n;
    cin >> x >> n;
    int ng[102] = {};
    for(int i = 0; i < n; i++){
        int p;
        cin >> p;
        ng[p] = true;
    }
    int ret = 0, score = 1<<30;
    for(int i = 0; i <= 101; i++){
        if(ng[i])   continue;
        if(abs(x-i) < score){
            ret = i;
            score = abs(x-i);
        }
    }
    cout << ret << endl;
    return 0;
}