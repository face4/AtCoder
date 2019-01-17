// UF + MST
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;

vector<int> p(100000), r(100000, 1);
int n;

void init(){
    for(int i = 0; i < n; i++)  p[i] = i;
}

int isParent(int x){
    if(x != p[x]){
        p[x] = isParent(p[x]);
    }
    return p[x];
}

void unite(int i, int j){
    int pi = isParent(i), pj = isParent(j);
    if(pi == pj)    return;

    if(r[pi] < r[pj]){
        p[pi] = pj;
        r[pj] += r[pi];
    }else{
        p[pj] = pi;
        r[pi] += r[pj];
    }
}

bool isSame(int i, int j){
    return isParent(i) == isParent(j);
}

struct data{
    int x, y, index;
};

bool compx(data a, data b){
    return a.x < b.x;
}

bool compy(data a, data b){
    return a.y < b.y;
}

int main(){
    cin >> n;
    init();

    vector<data> xa, ya;

    int x, y;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        data d{x, y, i};
        xa.push_back(d);
        ya.push_back(d);
    }

    sort(xa.begin(), xa.end(), compx);
    sort(ya.begin(), ya.end(), compy);

    priority_queue<pair<int,pair<int,int>>> pq;
    
    for(int i = 0; i < n; i++){
        if(i != 0){
            pq.push({-(xa[i].x-xa[i-1].x),{xa[i-1].index, xa[i].index}});
            pq.push({-(ya[i].y-ya[i-1].y),{ya[i-1].index, ya[i].index}});
        }
        if(i != n-1){
            pq.push({-(xa[i+1].x-xa[i].x),{xa[i].index, xa[i+1].index}});
            pq.push({-(ya[i+1].y-ya[i].y),{ya[i].index, ya[i+1].index}});
        }
        
    }

    ll ans = 0;
    while(!pq.empty()){
        auto p = pq.top();  pq.pop();
        int cost = -p.first;
        int i = p.second.first, j = p.second.second;
        if(isSame(i,j)) continue;
        ans += cost;
        unite(i,j);
    }

    cout << ans << endl;

    return 0;
}