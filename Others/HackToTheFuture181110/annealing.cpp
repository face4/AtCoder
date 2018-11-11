/// ### 
/// int tspSolver(void) を宣言して，その中に自分のアルゴリズムを書いてください．
/// 入出力データはグローバル変数でやりとりします．
/// 入力データは 都市数 n，都市座標の二次元配列 city[n][2] として入力されます．
/// 出力データは 順回路 tour[n], 順回路長 length で出力しますが，
/// length は最後に計算し直されるので，あまり出力する意味はありません．

/// 使用するグローバル変数等．必須項目
#define MAX 20000

#include <cmath>
#include <algorithm> // sort
#include <vector>
#include <iostream>
#include <climits>
#include <random>
using namespace std;

extern int n, length, tour[MAX];
extern float city[MAX][2];

// パラメータ
double T_START = 2000.0;
double T_END = 15.0;
double T_FACTOR = 0.98;
int SIZE = 5;
double EPS = 1>>7;

/// 順回路表示のための関数
/// tou[] に順回路の配列を，wai にウェイト時間(ミリ秒)，colorに色 0~3を指定．
extern void showTour(int *tou, int wai, int color);
/// color[] に配列を指定して，枝ごとに色を変えられる順回路表示．
extern void showCTour(int *tou, int wai, int *color);
/// 文字列を表示ウィンドウの上部バーに表示．数字等が表示したい場合 sprintf 等と組み合わせる．
extern void showString(char *str);
/// leng を暫定解として表示(標準エラー出力)
extern void showLength(int leng);
/// ###

/// 距離の計算はこの関数と同等の方法で行う．
int Dis(int i, int j)
{
    float xd, yd;
    xd = city[i][0] - city[j][0];
    yd = city[i][1] - city[j][1];
    return (int)(sqrt(xd * xd + yd * yd) + .5);
}

int cost_evaluate(int *t)
{
    int sum;
    sum = Dis(t[n - 1], t[0]);
    for (int i = 0; i < n - 1; i++) {
      sum += Dis(t[i], t[i + 1]);
    }
    return sum;
}

int tmpTour[MAX];

// 頂点iに隣接する頂点を配列adj[]のhead[i]~head[i+1]-1番目に頂点iに近い順に保存
// 隣接する頂点数NEIGHBORを10とする.
static const int NEIGHBOR = 10;
int adj[MAX*NEIGHBOR];
int head[MAX+1];

// 頂点の番号iを入力すると、現在のtour上における次の頂点を返す.
int next(int i){
    if(i == tour[n-1])  return tour[0];
    
    for(int k = 0; k < n-1; k++){
        if(tour[k] == i)  return tour[k+1];
    }
    
    return -1; // unreachable
}

int getIndex(int i){
    for(int k = 0; k < n; k++){
        if(tour[k] == i)    return k;
    }
    
    return -1; // unreachable
}

// 4つの頂点a,b,c,dでb = next(a), d = next(c)を満たすものを入力すると、
// 現在の順回路における枝ab,cdをac,bdに置き換える.さらに、tour[]上の頂点
// b,c間またはa,d間のすべての頂点を逆順にする.
void flip(int a, int b, int c, int d){
    a = getIndex(a);
    b = getIndex(b);
    c = getIndex(c);
    d = getIndex(d);
    
    if(b == (a+1)%n && d == (c+1)%n){
        if(a > d){
            swap(a,c);
            swap(b,d);
        }
        
        reverse(tour+b, tour+c+1);
        
        //swap(tour[b], tour[c]);
    }

}


void annealing(){
    // headの初期化(正直なくても良い.)
    for(int i = 0; i <= n; i++)  head[i] = i*min(n-1,NEIGHBOR);
    
    // adjの初期化(各頂点について直近の10頂点を計算し、adj[head[i]] ~ adj[head[i+1]-1]に頂点番号を書き込む)
    for(int i = 0; i < n; i++){
        // pair<距離、頂点番号>
        vector<pair<int,int> > near;
        for(int j = 0; j < n; j++){
            if(i == j)  continue;
            near.push_back(make_pair(Dis(tour[i],tour[j]), j));
        }
        sort(near.begin(), near.end());
        
        for(int j = 0; j < min(NEIGHBOR, n); j++){
            adj[head[i]+j] = near[j].second;
        }
        
    }

    // 乱数生成
    // http://program.station.ez-net.jp/special/handbook/cpp/numeric/random.asp
    random_device rd;
    vector<uint32_t> rsv(10);
    generate(rsv.begin(), rsv.end(), ref(rd));
    seed_seq rs(rsv.begin(), rsv.end());
    mt19937 randomEngine(rs);
    uniform_real_distribution<double> randomDoubleDistribution(0.0, 1.0);
    
    int i = 0;
    int j, a, b, c, d, tmp, count;
    double T;
    
    // 探索を打ち切る際にフラグを折る
    bool cont = true;
    
    for(T = T_START; T >= T_END && cont; T *= T_FACTOR){
        for(count = 0; count < SIZE * n && cont; count++){
            a = tour[i];
            b = next(a);
            for(j = head[a]; j < head[a+1]; j++){
                c = adj[j];
                if(b == c)  continue;
                d = next(c);
                if(b == d || a == d)    continue;
                tmp = Dis(a,b) + Dis(c,d) - (Dis(a,c) + Dis(b,d));
                
                // tmp/Tが無視できるほど小さくなったら探索を終える
                if(tmp < 0 && fabs(tmp/T) < EPS){
                    cont = false;
                    break;
                }
                // exp(tmp/T)のテイラー展開を1次で打ち切り
                if(tmp >= 0 || randomDoubleDistribution(randomEngine) < 1 + tmp/T){
                    length -= tmp;
                    flip(a, b, c, d);
                    showTour(tour, 1, 1);
                    break;
                }
            }
            i = (i+1)%n;
        }
    }
    
}

/// この関数の実行が終了した時点でtour[n]の巡回路がカラー0で表示される.
int tspSolver(void)
{
    for (int i = 0; i < n; i++) {
        tmpTour[i] = i;
    }
    for (int j = 0; j < n; j++) {
        tour[j] = tmpTour[j];
    }
    length = cost_evaluate(tour);
    annealing();
    return 0;
}
