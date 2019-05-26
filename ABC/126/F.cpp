#include<iostream>
#include<list>
using namespace std;

int main(){
    int m, k;
    cin >> m >> k;
    if((1<<m)-1 < k || m==1&&k==1){
        cout << -1 << endl;
        return 0;
    }
    if(k == 0){
        for(int i = 0; i < 1<<m; i++){
            cout << i << " " << i << " \n"[i==(1<<m)-1];
        }
        return 0;
    }
    list<int> ans;
    ans.push_back(k);
    for(int i = 0; i < 1<<m; i++){
        if(i==k)    continue;
        ans.push_front(i);
        ans.push_back(i);
    }
    ans.push_back(k);
    auto it = ans.begin();
    for(int i = 0; i < 1<<(m+1); i++){
        cout << *it << " \n"[i==((1<<(m+1))-1)];
        it++;
    }
    return 0;
}