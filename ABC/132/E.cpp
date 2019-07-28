#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct data{
    int pos, mod, num;
};

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> v[n];
    while(m-- > 0){
        int a, b;
        cin >> a >> b;
        v[--a].push_back(--b);
    }
    int s, t;
    cin >> s >> t;
    s--, t--;
    vector<vector<bool>> visit(3, vector<bool>(n, 0));
    queue<data> q;
    q.push(data({s,0,0}));
    while(!q.empty()){
        data d = q.front(); q.pop();
        visit[d.mod][d.pos] = true;
        for(int npos : v[d.pos]){
            int nmod = (d.mod+1)%3;
            int nnum = d.num + (nmod == 0);
            if(npos == t && nmod == 0){
                cout << nnum << endl;
                return 0;
            }
            if(!visit[nmod][npos]){
                visit[nmod][npos] = true;
                q.push(data({npos,nmod,nnum}));
            }
        }
    }
    cout << -1 << endl;
    return 0;
}