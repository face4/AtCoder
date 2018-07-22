// ソートすればO(1)で簡単に求められる.
// 解説を見るまで気付かなかった.
#include<iostream>
#include<set>
using namespace std;

int main(){
    set<int> s;
    int a[5];
    for(int i = 0; i < 5; i++)  cin >> a[i];

    for(int i = 0; i < 3; i++){
        for(int j = i+1; j < 4; j++){
            for(int k = j+1; k < 5; k++){
                s.insert(a[i]+a[j]+a[k]);
            }
        }
    }

    set<int>::iterator it = s.begin();
    for(int i = 0; i < s.size()-3; i++) it++;
    cout << *it << endl;

    return 0;
}