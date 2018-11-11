// 雑な焼き鈍しを導入.スコアが上がるかどうかは知らない.
#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<random>
#include<chrono>
using namespace std;
#define inRange(x, a, b) (a <= x && x < b)

int calcScore();
bool update();
void answer();
void calc();
pair<int,int> calc(int r, int op, int er);
int unweigh(int w);
void tryAndError(int i, int j, int w);

string s[500];
pair<int, int> stop[500];
vector<vector<char>> mat(29, vector<char>(29, '.'));
vector<vector<char>> ans(29, vector<char>(29, '.'));
set<int> ids[29][29];
int cnt[29][29] = {};
int n, m, l;
int score = 0;
char walls[6] = {'.', '#', 'D', 'T', 'L', 'R'};

// simulated annealing parameters
double T = 10.0;
double T_FACTOR = 0.98;

int calcScore(){
    int ret = 0;
    for(int i = 0; i < 29; i++){
        for(int j = 0; j < 29; j++){
            if(cnt[i][j] == 1)  ret += 10;
            if(cnt[i][j] == 2)  ret += 3;
            if(cnt[i][j] == 3)  ret += 1;
        }
    }
    return ret;
}

bool update(){
    int tmpscore = calcScore();
    if(tmpscore > score){
        score = tmpscore;
        ans = mat;
        return true;
    }else{
        return false;
    }
}

void answer(){
	for(int i = 0; i < 29; i++){
		for(int j = 0; j < 29; j++){
			cout << ans[i][j];
		}
		cout << endl;
	}
}

void calc(){
	memset(cnt, 0, sizeof(cnt));
	for(int i = 0; i < 29; i++) for(int j = 0; j < 29; j++) ids[i][j].clear();

	for(int r = 0; r < 500; r++){
		int i = m/2, j = m/2, di = -1, dj = 0;
        ids[i][j].insert(r);
		for(char c : s[r]){
			int times = 1;
			if(mat[i][j] == 'D') times = 2;
			if(mat[i][j] == 'T') times = 3;
			
			if(c == 'S'){
				int ni = i+times*di, nj = j+times*dj;
				if(inRange(ni, 0, m) && inRange(nj, 0, m) && mat[ni][nj] != '#'){
					i = ni, j = nj;
                    ids[i][j].insert(r);
				}
			}else if(c == 'L'){
				while(times-- > 0){
					swap(di, dj);
				    di *= -1;
			    }
			}else if(c == 'R'){
				while(times-- > 0){
					swap(di, dj);
				    dj *= -1;
				}
			}
        }
        cnt[i][j]++;
        stop[r] = {i, j};
	}

	return;
}

// op : 0 -> 足跡を残さない. 
// 1 -> 足跡を残す(し、stopも更新する.つまり、一連の行動を完全に確定する). 
// -1 -> 足跡を消す
pair<int, int> calc(int r, int op){
	pair<int, int> ret;
	int i = m/2, j = m/2, di = -1, dj = 0;
	for(char c : s[r]){
        if(op == 1)  ids[i][j].insert(r);
		if(op == -1)  ids[i][j].erase(r);

        int times = 1;
		if(mat[i][j] == 'D') times = 2;
		if(mat[i][j] == 'T') times = 3;
		
		if(c == 'S'){
			int ni = i+times*di, nj = j+times*dj;
			if(inRange(ni, 0, m) && inRange(nj, 0, m) && mat[ni][nj] != '#'){
			    i = ni, j = nj;
			}
		}else if(c == 'L'){
			while(times-- > 0){
				swap(di, dj);
			    di *= -1;
		    }
		}else if(c == 'R'){
			while(times-- > 0){
				swap(di, dj);
			    dj *= -1;
			}
		}
    }
    if(op == 1)  stop[r] = {i,j};
    ret = {i,j};
	return ret;
}

// if文9つは流石に重いかもしれない
int unweigh(int w){
    if(w <= 3)  return w;
    if(w <= 9)  return 3+(w%3 == 0 ? 3 : w%3);
    if(w <= 21) return 6+(w%3 == 0 ? 3 : w%3);
    if(w <= 39) return 9+(w%3 == 0 ? 3 : w%3);
    if(w <= 57) return 12+(w%3 == 0 ? 3 : w%3);
    if(w <= 75) return 15+(w%3 == 0 ? 3 : w%3);
    if(w <= 87) return 18+(w%3 == 0 ? 3 : w%3);
    if(w <= 93) return 21+(w%3 == 0 ? 3 : w%3);
    if(w <= 96) return 24+(w%3 == 0 ? 3 : w%3);
}

void tryAndError(int i, int j, int w){
    char before = mat[i][j];
    mat[i][j] = walls[w];
    int diffscore = 0;

    int add[29][29] = {};

    set<int> tmpids = ids[i][j];
    for(int r : ids[i][j]){
        int a = stop[r].first, b = stop[r].second;
        cnt[a][b]--;    add[a][b]++;
        
        if(cnt[a][b] == 0)  diffscore -= 10;
        else if(cnt[a][b] == 1) diffscore += 7;
        else if(cnt[a][b] == 2) diffscore += 2;
        else if(cnt[a][b] == 3) diffscore += 1;

        pair<int,int> next = calc(r, 0);

        a = next.first, b = next.second;
        cnt[a][b]++;    add[a][b]--;
        
        if(cnt[a][b] == 1)  diffscore += 10;
        else if(cnt[a][b] == 2) diffscore -= 7;
        else if(cnt[a][b] == 3) diffscore -= 2;
        else if(cnt[a][b] == 4) diffscore -= 1;
    }

    double prob = (double)rand() / RAND_MAX;

    if(diffscore > 0 || prob < 1 - diffscore/T){
        // 足跡を消す. cntは既に上のforループで処理済みなのでerは0.
        mat[i][j] = before;
        for(int r : tmpids) pair<int,int> trash = calc(r, -1);
        mat[i][j] = walls[w];
        for(int r : tmpids) pair<int,int> trash = calc(r, 1);

        score += diffscore;
        ans = mat;
    }else{
        mat[i][j] = before;
        // 上のforループでめちゃくちゃにしてしまったcnt配列を元に戻す
        for(int i = 0; i < 29; i++){
            for(int j = 0; j < 29; j++){
                cnt[i][j] += add[i][j];
            }
        }
    }
    
    T *= T_FACTOR;

    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    auto start = std::chrono::system_clock::now(); 
    random_device rnd;
    mt19937 mt(rnd());
    uniform_int_distribution<int> rand30(1,96);
    uniform_int_distribution<int> wall6(0,5);
	// rand30k(mt)

    cin >> n >> m >> l;
	
	for(int i = 0; i < n; i++) cin >> s[i];
	
	// wall
	for(int i = 0; i < m; i++){
		for(int j = 0; j < m; j++){
			mat[i][j] = (i==0 || i ==m-1 || j ==0 || j ==m-1) ? '#' : '.';
		}
	}

	ans = mat;

	calc();
    
    uniform_real_distribution<double> random(0.0, 1.0);
    double T_START = 2000.0;
    double T_END = 15.0;
    double T_FACTOR = 0.98;
    
    while(true){
        auto now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()-start).count();
        if(now > 2985)  break;
        int i = unweigh(rand30(mt));
        int j = unweigh(rand30(mt));
        int w = wall6(mt);
        if(mat[i][j] == walls[w] || (i == m/2 && j == m/2 && w == 1))   continue;

        // ここを変えた！！
        tryAndError(i, j, w);
    }

	answer();
	
	return 0;
}
