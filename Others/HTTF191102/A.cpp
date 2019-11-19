// 無駄な移動マスを消すようにしてみたけど多分効果0
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

typedef pair<int,int> pii;
#define inRange(x,a,b) (a <= x && x < b)
int di[4] = {0,0,1,-1};
int dj[4] = {1,-1,0,0};

int r[400][400];
int ri[100], rj[100];
int ans[400][400] = {};
int change[400][400] = {};
bool ng[400][400] = {};

int n, m, b, gi, gj;

void answer(){
    vector<pii> vp;
    vector<char> vc;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(ans[i][j] < 4){
                vp.push_back({i,j});
                vc.push_back("RLDU"[ans[i][j]]);
            }
        }
    }
    cout << vp.size() << endl;
    for(int i = 0; i < vp.size(); i++){
        cout << vp[i].first << " " << vp[i].second << " " << vc[i] << endl;
    }
}

void init(){
    memset(r, 0x3f, sizeof(r));
    memset(ans, 0x3f, sizeof(ans));
}

int char2int(char c){
    if(c == 'U')    return 3;
    if(c == 'D')    return 2;
    if(c == 'L')    return 1;
    if(c == 'R')    return 0;
}

void reduce(){
    for(int x = 0; x < m; x++){
        int i = ri[x], j = rj[x], way = r[ri[x]][rj[x]];
        while(i != gi || j != gj){
            if(ans[i][j] < 4){
                change[i][j] += way!=ans[i][j];
                way = ans[i][j];
            }
            i = (i+di[way]+n)%n, j = (j+dj[way]+n)%n;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(change[i][j] == 0)   ans[i][j] = 5;
        }
    }
}

void reduce2(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(ans[i][j] > 3)   continue;
            int cp = ans[i][j];
            ans[i][j] = 5;
            bool ok = true;
            for(int k = 0; k < m; k++){
                int xi = ri[k], xj = rj[k], way = r[xi][xj];
                int step = 0;
                while(!ng[xi][xj] && step <= 1605 && (xi != gi || xj != gj)){
                    step++;
                    if(ans[xi][xj] < 4)   way = ans[xi][xj];
                    xi = (xi+di[way]+n)%n, xj = (xj+dj[way]+n)%n;
                }
                if(ng[xi][xj] || step > 1605){
                    ok = false;
                    break;
                }
            }
            cerr << i << " " << j << " " << ok << endl;
            if(!ok)  ans[i][j] = cp;
        }
    }
}

void construct(){
    queue<pii> q;
    q.push({gi,gj});
    while(!q.empty()){
        pii p = q.front();  q.pop();
        int i = p.first, j = p.second;
        for(int k = 0; k < 4; k++){
            int ni = (i+di[k]+n)%n, nj = (j+dj[k]+n)%n;
            if(ng[ni][nj] || ans[ni][nj] < 4)   continue;
            ans[ni][nj] = k xor 1;
            q.push({ni,nj});
        }
    }
}

void deb(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == gi && j == gj)      cout << "!";
            else if(ng[i][j])           cout << "X";
            else if(ans[i][j] > 3)      cout << " ";
            else                        cout << "RLDU"[ans[i][j]];
        }
        cout << endl;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    init();
    cin >> n >> m >> b;
    cin >> gi >> gj;
    for(int i = 0; i < m; i++){
        char c;
        cin >> ri[i] >> rj[i] >> c;
        r[ri[i]][rj[i]] = char2int(c);
    }
    while(b-- > 0){
        int i, j;
        cin >> i >> j;
        ng[i][j] = true;
    }
    construct();
    reduce();
    reduce2();
    answer();
    return 0;
}