#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

struct edge{
    int to, cap, rev;
};

#define MAX_V 101
vector<edge> G[MAX_V];
bool used[MAX_V];

void add_edge(int from, int to, int cap){
    G[from].push_back((edge){to, cap, (int)G[to].size()});
    G[to].push_back((edge){from, 0, (int)G[from].size()-1});
}

// v...target vertex, t...end vertex, f...maximum flow 
int dfs(int v, int t, int f){
    if(v == t)  return f;

    used[v] = true;
    for(int i = 0; i < G[v].size(); i++){
        edge &e = G[v][i];
        if(!used[e.to] && e.cap > 0){
            int d = dfs(e.to, t, min(f, e.cap));
            if(d > 0){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }

    return 0;
}

const int INF = 1<<29;

// maxflow from s to t
int max_flow(int s, int t){
    int flow = 0;
    while(1){
        memset(used, 0, sizeof(used));
        int f = dfs(s, t, INF);
        if(f == 0)  return flow;
        flow += f;
    }
}

int main(){
    int SOURCE = 0, SINK = 100;
    int n, g, e;
    cin >> n >> g >> e;
    while(g-- > 0){
        int p;  cin >> p;
        add_edge(p, SINK, 1);
        add_edge(SINK, p, 1);
    }
    while(e-- > 0){
        int a, b;
        cin >> a >> b;
        add_edge(a, b, 1);
        add_edge(b, a, 1);
    }
    cout << max_flow(SOURCE, SINK) << endl;
    return 0;
}