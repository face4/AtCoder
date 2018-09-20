#include<iostream>
#include<map>
using namespace std;

int main(){
    int n, a;
    cin >> n;

    map<int, int> appear;
    for(int i = 0; i < n; i++){
        cin >> a;
        appear[a]++;
    }

    int del = 0, two = 0;
    for(pair<int,int> p : appear){
        if(p.second == 1)   continue;
        while(p.second >= 3){
            del+=2;
            p.second -= 2;
        }
        if(p.second == 2)   two++;
    }

    del += ((two+1)/2) * 2;

    cout << n - del << endl;

    return 0;
}