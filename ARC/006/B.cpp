#include<iostream>
using namespace std;
#define inRange(x,a,b) a <= x && x < b

int main(){
    int n, l;
    cin >> n >> l;

    cin.ignore();

    string s[l], in;

    for(int i = 0; i < l; i++){
        getline(cin, in);
        s[i] = in;
    }  

    string last;
    getline(cin, last);

    int pos;
    for(pos = 0;;pos++) if(last[pos] == 'o')    break;

    for(int i = l-1; i >= 0; i--){
        int left = pos-1, right = pos+1;
        if(inRange(left, 0, 2*n-1) && s[i][left] == '-')    pos -= 2;
        if(inRange(right, 0, 2*n-1) && s[i][right] == '-')    pos += 2;
    }

    cout << pos/2+1 << endl;

    return 0;
}