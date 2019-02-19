#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<random>
#include<chrono>
#include<cfloat>
#include<queue>
using namespace std;
#define inRange(x,a,b) (a <= x && x < b)

int di[8] = {0,0,1,-1,1,1,-1,-1};
int dj[8] = {1,-1,0,0,1,-1,1,-1};

typedef long long ll;
typedef pair<int,int> pii;

#define x first
#define y second

int n, m;
int a[50][50];

void input(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
}

queue<pair<int,int>> taken;

bool f(int r, int c){
    queue<pair<int,int>> q, tmptaken;
    vector<vector<bool>> visit(50, vector<bool>(50, 0));
    q.push({r,c});
    int count = 0;
    while(!q.empty()){
        pair<int,int> p = q.front();    q.pop();
        int h = p.first, w = p.second;
        if(visit[h][w]) continue;
        visit[h][w] = true;
        tmptaken.push({h,w});
        count++;
        for(int k = 0; k < 4; k++){
            int nh = h + di[k], nw = w + dj[k];
            if(!inRange(nh, 0, 50) || !inRange(nw, 0, 50) || visit[nh][nw] || a[nh][nw] != a[r][c])  continue;
            q.push({nh, nw});
        }
    }
    taken = tmptaken;
    return count >= a[r][c];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    auto start = std::chrono::system_clock::now(); 
    random_device rnd;
    mt19937 mt(rnd());
    uniform_int_distribution<int> rand4(0, 4);
    uniform_int_distribution<int> rand50(0, 49);

    input();

    for(int i = 0; i < m; i++){
        int r, c;

        while(1){
            r = rand50(mt);
            c = rand50(mt);
            if(a[r][c] == 0)    continue;
            if(f(r, c)){
                // harvest
                while(!taken.empty()){
                    pair<int,int> p = taken.front();    taken.pop();
                    a[p.first][p.second] = 0;
                }
                cout << 2 << " " << r << " " << c << endl;
            }else{
                // caltivate
                cout << 1 << " " << r << " " << c << endl;
            }
            break;
        }
    }

	return 0;
}