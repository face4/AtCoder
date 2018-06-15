#include<iostream>
#include<set>
using namespace std;

int main(){
    // 解説の解法
    set<int> flower;
    int n, a;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        flower.insert(a);
    }
    cout << n-flower.size() << endl;
    
    /* 自分の解法
    bool visit[100001] = {};
    int n, a, cnt = 0;
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        if(visit[a])    cnt++;
        visit[a] = true;
    }

    cout << cnt << endl;
    */
    return 0;
}