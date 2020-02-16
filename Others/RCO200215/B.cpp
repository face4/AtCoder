#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<random>
#include<chrono>
using namespace std;

#define inRange(x,a,b) (a <= x && x < b)

int n, m;
int goal[50][50], now[50][50] = {};
int ansi[500], ansj[500];
char way[500];


int zante = 0;
int fansi[500], fansj[500];
char fway[500];

typedef pair<int,int> pii;

int di[8] = {0,0,1,-1,1,1,-1,-1};
int dj[8] = {1,-1,0,0,1,-1,1,-1};
char c[4] = {'R', 'L', 'D', 'U'};


void answer(){
    for(int i = 0; i < m; i++){
        cout << fansi[i];
        if(ansi[i] != -1)   cout << " " << fansj[i] << " " << fway[i];
        cout << "\n";
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);


    auto start = std::chrono::system_clock::now(); 
    random_device rnd;
    mt19937 mt(rnd());
    uniform_int_distribution<int> rand50(0, 49);
    uniform_real_distribution<double> prob(0.0, 1.0);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> goal[i][j];
        }
    }

    while(true){
        auto NOW = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()-start).count();
        if(NOW > 1700)  break;
        
        memset(now, 0x3f, sizeof(now));

        double T = 1.0;
        double T_FACTOR = 0.99999955;

        set<pii> c2p[4];
        c2p[0].insert({0,0});       now[0][0] = 0;
        c2p[1].insert({0,n-1});     now[0][n-1] = 1;
        c2p[2].insert({n-1,0});     now[n-1][0] = 2;
        c2p[3].insert({n-1,n-1});   now[n-1][n-1] = 3;
        
        int fi[4][2] = {
            {0, 2},
            {2, 1},
            {0, 3},
            {3, 1}
        };

        int next[4] = {};
        int befi[4], befj[4];
        befi[0] = 0;        befj[0] = 0;
        befi[1] = 0;        befj[1] = n-1;
        befi[2] = n-1;      befj[2] = 0;
        befi[3] = n-1;      befj[3] = n-1;
        for(int i = 0; i < 19*4; i++){
            int W = fi[i%4][next[i%4]];
            next[i%4] = 1-next[i%4];
            ansi[i] = befi[i%4], ansj[i] = befj[i%4];
            way[i] = c[W];
            for(int k = 0; k < 5; k++){
                befi[i%4] += di[W];
                befj[i%4] += dj[W];
                if(!inRange(befi[i%4],0,n)||!inRange(befj[i%4],0,n))  break;
                if(now[befi[i%4]][befj[i%4]] != i%4){
                    if(now[befi[i%4]][befj[i%4]] < 4) c2p[now[befi[i%4]][befj[i%4]]].erase({befi[i%4],befj[i%4]});
                    now[befi[i%4]][befj[i%4]] = i%4;
                    c2p[now[befi[i%4]][befj[i%4]]].insert({befi[i%4],befj[i%4]});
                }
            }
            if(i/4 < 2){
                for(int j = 0; j < i%4+1; j++)    befi[i%4]-=di[W], befj[i%4]-=dj[W];
            }
        }

        for(int i = 19*4; i < m; i++){
            T *= T_FACTOR;
            // bad :(
            if(c2p[i%4].size() == 0){
                ansi[i] = -1;
                continue;
            }

            int choice = 0;
            int besti = -1, bestj = -1, bests = 0, bestc = 0, ma = 500;
            for(int loop = 0; loop < ma; loop++){
                uniform_int_distribution<int> rand(0, c2p[i%4].size()-1);
                int ind = rand(mt);
                auto it = c2p[i%4].begin();
                while(ind--)    it++;
                ansi[i] = it->first, ansj[i] = it->second;
                int score = -1;
                for(int k = 0; k < 4; k++){
                    int ni = ansi[i], nj = ansj[i], tmps = 0;
                    for(int step = 0; step < 5; step++){
                        ni += di[k], nj += dj[k];
                        if(!inRange(ni,0,n)||!inRange(nj,0,n))  break;
                        int add = 1;
                        if(now[ni][nj]>3)   add *= prob(mt)<T ? 1 : 7;
                        if(now[ni][nj]!=i%4)    add *= prob(mt)<T ? 14 : 1;
                        if(goal[ni][nj]==i%4)    add *= (prob(mt)<T ? 4 : 1)*(now[ni][nj]==i%4 ? 2 : 8);
                        if(goal[ni][nj]!=i%4&&goal[ni][nj]==now[ni][nj])    add /= prob(mt)>T ? 1 : 2;
                        tmps += add;
                    }
                    if(tmps > score)    score = tmps, choice = k;
                }
                if(score > bests){
                    bests = score;
                    besti = ansi[i], bestj = ansj[i];
                    bestc = choice;
                }
            }
            ansi[i] = besti, ansj[i] = bestj;
            choice = bestc;
            int ni = ansi[i], nj = ansj[i];
            for(int step = 0; step < 5; step++){
                ni += di[choice], nj += dj[choice];
                if(!inRange(ni,0,n)||!inRange(nj,0,n))  break;
                if(now[ni][nj] != i%4){
                    if(now[ni][nj] < 4) c2p[now[ni][nj]].erase({ni,nj});
                    now[ni][nj] = i%4;
                    c2p[now[ni][nj]].insert({ni,nj});
                }
            }
            way[i] = c[choice];
        }

        int tmpscore = 0;
        for(int i = 0; i < 4; i++)  for(pii p : c2p[i]) tmpscore += goal[p.first][p.second]==i;
        if(tmpscore > zante){
            for(int i = 0; i < m; i++)  fansi[i] = ansi[i], fansj[i] = ansj[i], fway[i] = way[i];
        }
    }

    answer();



	return 0;
}
