// count配列の計算には300*500=150000.
// 考慮すべきマス目は27*27=729.
// それらマス目は空、壁、2回、3回、LtoR、RtoLの6通り
// 全パターン考慮は729*6*150000 = 9^4 * 10^5 = 6.6 * 10^9 -> 到底間に合わない
// マス目について、そのマスを通る命令列のidをマス目に登録しておき
// 、マス目を変えるときは影響のある命令列のみ考慮することにするとうまくいく？

#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<random>
#include<chrono>
using namespace std;
#define inRange(x, a, b) (a <= x && x < b)

string s[500];
pair<int, int> stop[500];
vector<vector<char>> mat(29, vector<char>(29, '.'));
vector<vector<char>> ans(29, vector<char>(29, '.'));
set<int> ids[29][29];
int cnt[29][29] = {};
int n, m, l;
int score = 0;
char walls[6] = {'.', '#', 'D', 'T', 'L', 'R'};

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
		for(char c : s[r]){
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
        cnt[i][j]++;
        stop[r] = {i, j};
	}

	return;
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

    while(true){
        auto now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()-start).count();
        if(now > 2992)  break;
        int i = unweigh(rand30(mt));
        int j = unweigh(rand30(mt));
        int w = wall6(mt);
        if(i == m/2 && j == m/2 && w == 1)  continue;
        if(mat[i][j] == walls[w])   continue;
        char before = mat[i][j];
        mat[i][j] = walls[w];
        calc();
        if(!update())   mat[i][j] = before;
    }

	answer();
	
	return 0;
}

// pair<int, int> calc(int r){
// 	pair<int, int> ret;
// 	int i = m/2, j = m/2, di = -1, dj = 0;
// 	for(char c : s[r]){
// 			int times = 1;
// 			if(mat[i][j] == 'D') times = 2;
// 			if(mat[i][j] == 'T') times = 3;
			
// 			if(c == 'S'){
// 				int ni = i+times*di, nj = j+times*dj;
// 				if(inRange(ni, 0, m) && inRange(nj, 0, m) && mat[ni][nj] != '#'){
// 				    i = ni, j = nj;
// 				}
// 			}else if(c == 'L'){
// 				while(times-- > 0){
// 					swap(di, dj);
// 				    di *= -1;
// 			    }
// 			}else if(c == 'R'){
// 				while(times-- > 0){
// 					swap(di, dj);
// 				    dj *= -1;
// 				}
// 			}
//     }
//     ret = {i,j};
// 	return ret;
// }