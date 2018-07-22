#include<iostream>
#include<map>
using namespace std;

int main(){
    int n, a;
    cin >> n;

    map<int,int> appear;
    for(int i = 0; i < n; i++){
        cin >> a;
        appear[a]++;
    }

    int ans = 0;
    for(map<int,int>::iterator it = appear.begin(); it != appear.end(); it++){
        pair<int,int> p = *it;
        if(p.second < p.first)  ans += p.second;
        else                        ans += p.second - p.first;
    }

    cout << ans << endl;

    return 0;
}