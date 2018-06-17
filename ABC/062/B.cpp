#include<iostream>
using namespace std;

int main(){
    string s;
    int h, w;
    cin >> h >> w;

    for(int i = 0; i < w+2; i++)  cout << "#";
    cout << endl;

    for(int i = 0; i < h; i++){
        cin >> s;
        cout << "#" << s << "#" << endl;
    }

    for(int i = 0; i < w+2; i++)  cout << "#";
    cout << endl;

    return 0;
}