#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    string s;
    int n, l, r;
    cin >> s >> n;

    for(int i = 0; i < n; i++){
        cin >> l >> r;
        // l-1のようにr-1、とならないのは、ちょっと考えればわかること
        reverse(s.begin()+l-1, s.begin()+r);
        /*
        l--; r--;
        for(int j = 0; j < (r-l+1)/2; j++){
            swap(s[l+j], s[r-j]);
        }
        */
    }

    cout << s << endl;
    return 0;
}