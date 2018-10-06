#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;

struct edge{
    int to;
    int cost;
    edge(int t, ll c) : to(t), cost(c) {}
};

vector<edge> v[100000];
bool visit[100000] = {};
ll value[100000] = {};
bool judge = true;

void dfs(int s, ll accum){
    visit[s] = true;
    value[s] = accum;
    for(edge e : v[s]){
        if(!visit[e.to]){
            dfs(e.to, value[s] + e.cost);
        }else{
            if(value[s] + e.cost != value[e.to]){
                judge = false;
                return;
            }
        }
    }
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    int l, r, d;
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &l, &r, &d);
        l--, r--;
        v[l].push_back(edge(r,d));
        v[r].push_back(edge(l,-d));
    }

    for(int i = 0; i < n; i++){
        if(!visit[i]){
            dfs(i, 0);
        }
    }

    if(judge)   cout << "Yes" << endl;
    else        cout << "No" << endl;

    return 0;
}