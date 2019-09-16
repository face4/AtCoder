#include<iostream>
#include<set>
#include<queue>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(1<<n);
    set<pair<int,int>> m;
    priority_queue<pair<int,int>> q;
    for(int i = 0; i < 1<<n; i++){
        int x;  cin >> x;
        m.insert({x, i});
    }
    q.push(*(m.rbegin()));
    m.erase(--m.end());
    for(int i = 0; i < n; i++){
        priority_queue<pair<int,int>> nextq = q;
        while(!q.empty()){
            pair<int,int> from = q.top();    q.pop();
            auto it = m.lower_bound({from.first, -1});
            if(it == m.begin()){
                cout << "No" << endl;
                return 0;
            }
            it--;
            pair<int,int> to = *it;
            m.erase(it);
            nextq.push(to);
        }
        q = nextq;
    }
    cout << "Yes" << endl;
    return 0;
}