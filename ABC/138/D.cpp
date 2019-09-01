#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;

int main(){
    int n, Q;
    cin >> n >> Q;
    vector<int> v[n];
    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<ll> add(n, 0);
    while(Q-- > 0){
        int p, x;
        cin >> p >> x;
        p--;
        add[p] += x;
    }
    vector<bool> visit(n, 0);
    queue<int> q;
    visit[0] = true;
    for(int j : v[0])   q.push(j), visit[j] = true, add[j] += add[0];
    while(!q.empty()){
        int now = q.front();    q.pop();
        for(int child : v[now]){
            if(!visit[child]){
                q.push(child);
                visit[child] = true;
                add[child] += add[now];
            }
        }
    }
    for(int i = 0; i < n; i++)  cout << add[i] << " \n"[i+1==n];
    return 0;
}