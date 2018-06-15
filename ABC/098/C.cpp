#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;

    int forward[n] = {};
    int backward[n] = {};
    int total[n];

    for(int i = 1; i < n; i++){
        if(s[i-1]=='W') forward[i] = forward[i-1]+1;
        else            forward[i] = forward[i-1];
    }

    for(int i = n-2; i >= 0; i--){
        if(s[i+1]=='E') backward[i] = backward[i+1]+1;
        else            backward[i] = backward[i+1];
    }

    for(int i = 0; i < n; i++){
        total[i] = forward[i]+backward[i];
    }

    sort(total, total+n);

    cout << total[0] << endl;
    return 0;
}