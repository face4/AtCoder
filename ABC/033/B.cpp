#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    string s[n];
    int p[n], sum = 0, largestP = -1, largestT;

    for(int i = 0; i < n; i++){
        cin >> s[i] >> p[i];
        sum += p[i];
        if(p[i] > largestP){
            largestP = p[i];
            largestT = i;
        }
    }

    sum /= 2;

    if(largestP > sum){
        cout << s[largestT] << endl;
    }else{
        cout << "atcoder" << endl;
    }

    return 0;
}