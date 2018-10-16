#include<iostream>
#include<climits>
using namespace std;

typedef long long ll;

struct Edge{int from, to; ll cost;};

const ll INF = 1ll<<50;

int main(){
    int n, m, a, b;
    ll c;
    cin >> n >> m;

    Edge es[m];

    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        a--, b--;
        es[i].from = a, es[i].to = b, es[i].cost = -c;
    }

    ll score[n];
    for(int i = 0; i < n; i++)  score[i] = 0;

    bool neg = false;
    for(int i = 0; i < 2*n; i++){
        for(int j = 0; j < m; j++){
            Edge e = es[j];
            if(score[e.from] + e.cost < score[e.to]){
                score[e.to] = score[e.from] + e.cost;
                if(i >= n-1 && e.to == n-1)    neg = true;
            }
        }
    }

    if(neg){
        cout << "inf" << endl;
        return 0;
    }

    for(int i = 0; i < n; i++)  score[i] = INF;
    score[0] = 0;

    for(int i = 0; i < n-1; i++){    
        for(int j = 0; j < m; j++){
            Edge e = es[j];
            if(score[e.from] == INF)  continue;
            if(score[e.from] + e.cost < score[e.to]){
                score[e.to] = score[e.from] + e.cost;
            }
        }
    }

    cout << -score[n-1] << endl;
    return 0;
}