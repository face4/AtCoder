#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int n;
vector<vector<int>> v(100000);

void bfs(int from, int* arr){
    stack<pair<pair<int,int>, int>> s;    
    s.push({{-1, from}, 0});
    while(!s.empty()){
        pair<pair<int,int>,int> x = s.top();    s.pop();
        int parent = x.first.first;
        int now = x.first.second;
        int depth = x.second;
        arr[now] = depth;
        for(int next : v[now]){
            if(next != parent)  s.push({{now, next}, depth+1});
        }
    }
}

int main(){
    cin >> n;

    int a, b;
    for(int i = 0; i < n-1; i++){
        cin >> a >> b;
        a--, b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int disto[n], distn[n];
    bfs(0, disto);
    bfs(n-1, distn);

    int fen = 0, snu = 0;
    for(int i = 0; i < n; i++){
        if(distn[i] >= disto[i])    fen++;
        else                        snu++;
    }

    if(fen <= snu)  cout << "Snuke" << endl;
    else            cout << "Fennec" << endl;

    return 0;
}