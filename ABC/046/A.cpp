#include<iostream>
#include<set>
using namespace std;

int main(){
    set<int> colors;
    int c;

    for(int i = 0; i < 3; i++){
        cin >> c;
        colors.insert(c);        
    }

    cout << colors.size() << endl;
    return 0;
}