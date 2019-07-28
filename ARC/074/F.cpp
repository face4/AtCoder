#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

struct edge{
    int to, cap, rev;
};

#define MAX_V 300
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

int di[8] = {0,0,1,-1,1,1,-1,-1};
int dj[8] = {1,-1,0,0,1,-1,1,-1};
#define inRange(x,a,b) (a <= x && x < b)

// 解説AC
int main(){
    int h, w;
    cin >> h >> w;
    auto f = [=](int i, int j)->int{
        return i*w+j;
    };
    int si, sj, gi, gj;
    char mat[h][w];
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> mat[i][j];
            if(mat[i][j] == 'S'){
                si = i, sj = j;
                mat[i][j] = 'o';
            }else if(mat[i][j] == 'T'){
                gi = i, gj = j;
                mat[i][j] = 'o';
            }
        }
    }
    if(si == gi || sj == gj){
        cout << -1 << endl;
        return 0;
    }
    int SOURCE = 298, SINK = 299;
    // 始点・終点につながっている辺の容量を極端に大きくすることで
    // 最小カットによって蓮S, Tがカットされないようにする
    add_edge(SOURCE, si, INF);
    add_edge(SOURCE, h+sj, INF);
    add_edge(gi, SINK, INF);
    add_edge(h+gj, SINK, INF);
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(mat[i][j] != 'o')    continue;
            add_edge(i, h+j, 1);
            add_edge(h+j, i, 1);
        }
    }
    cout << max_flow(SOURCE, SINK) << endl;
    return 0;
}