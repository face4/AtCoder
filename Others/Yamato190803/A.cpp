/*
    submission 1 (8/4 16:25)
    サンプルが合ったので取り敢えず出してみることにする
    【未確認】
    ・車両の移動クエリについて、到達不能な場合が正しく計算できているかどうか

    submission2 (8/4 17:32)
    1ケースだけWAの理由がわからない
    clarに対する回答が回答になっていない気がする(commyさんの質問、後半部分)
    一方通行規則に矛盾する交差点情報が与えられる可能性があるものとして
    チェックを入れたものを提出することにする
    ------> 意味がなかった、1WAのまま変わらず

    submission3 (8/4 18:02)
    距離は10000*1000が最大だと思ったのでintで計算していたが、
    WAの原因が全くわからないのでひとまずオーバーフローを疑って
    距離を全てlong longで書いて出してみることにする(ムダ)
    それだけだと本当にムダなのでおまけで雑にcartの構築でさぼっていた部分を真面目に
    やるように変更してみる(コメントアウトした部分)
    ------> やはり意味がなかった、1WAのまま変わらず

    submission4 (8/4 20:48)
    端点からの距離が0や道の長さと等しい場合に道の端点が必ずしもonRoadの両端になっているとは限らないことに気付いた
    比較関数を書き換えることにより対策 これでWAが消えたらうれしい
    ------> 消えなかった　もうわからない
    
 */

/*
    crossはroadとの距離が0の点として扱うことにする
    一方通行か否か -> 0がundirected, 1がdirected
    車はdirectedグラフ上
    台車はundirectedグラフ上
    2つのグラフを同じデータで表せたら万々歳だが、最初から
    そう書くのは難しそうなのでまずは別で書くことにする
 */

/*  
    登場する点を全て整数値で扱う
       0  -   999   road (start)
    1000  -  1999   road (end)
    2000  -  2999   parking
    3000  -  3999   deliver
 */

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>
using namespace std;
typedef long long ll;

// from char to integer
int getId(char *c){
    return 100*(c[1]-'0') + 10*(c[2]-'0') + c[3]-'0';
}

struct point{
    int dist, id;
    point(int d, int i) : dist(d), id(i) {};
    bool operator<(const point other) const{
        if(dist != other.dist)              return dist < other.dist;
        else if(id < 1000)                  return true;
        else if(other.id < 1000)            return false;
        else if(1000 <= id && id < 2000)    return false;
        else if(1000 <= other.id && other.id < 2000)    return true;
        else                                return id < other.id;
    }
};

struct edge{
    int to, dist;
    edge(int t, int d) : to(t), dist(d) {};
};

int main(){
    int roadNum, crossNum, parkNum, deliverNum, queryNum;
    scanf("%d %d %d %d %d\n", &roadNum, &crossNum, &parkNum, &deliverNum, &queryNum);

    // 道の長さ、一方通行フラグを記憶 (key : 道路id)
    vector<int> roadLen(1000), roadFlag(1000);

    // 道路の始点、終点、駐車箇所、配達箇所を記憶　(key : 道路id)
    vector<point> onRoad[1000];

    // 駐車箇所、配達先の始点からの距離を記憶 (key : 駐車箇所idもしくは配達先id  val : 道路の始点からの距離)
    vector<int> fromStart(4000);
    
    // 交差点情報を記憶 (key : 交差点idとは無関係な通し番号  val : 始点と終点を対にしたpair)
    vector<pair<int,int>> cross(crossNum);

    // 駐車箇所がどの道路上にあるかを記憶 (key : 駐車箇所id  val : 道路id)
    vector<int> p2r(4000);

    // 配達先がどの道路上にあるかを記憶 (key : 配達先id  val : 道路id)
    vector<int> d2r(4000);

    // 入力をとる
    {
        for(int i = 0; i < roadNum; i++){
            char r[5]; int len, flag;
            scanf("%s %d %d\n", r, &len, &flag);
            int rid = getId(r);
            roadLen[rid] = len; roadFlag[rid] = flag;
            onRoad[rid].push_back(point(0, rid));
            onRoad[rid].push_back(point(len, rid+1000));
        }

        for(int i = 0; i < crossNum; i++){
            char c[5], rin[7], rout[7];
            scanf("%s %s %s\n", c, rin, rout);
            int rinId = getId(rin), routId = getId(rout);
            if(rin[4] == 'S')   rinId += 1000;
            if(rout[4] == 'E')  routId += 1000;
            cross[i] = {rinId, routId};
        }

        for(int i = 0; i < parkNum; i++){
            char p[7], r[5];    int len;
            scanf("%s %s %d\n", p, r, &len);
            int pid = 2000+getId(p), rid = getId(r);
            p2r[pid] = rid;
            onRoad[rid].push_back(point(len, pid));
            fromStart[pid] = len;
        }

        for(int i = 0; i < deliverNum; i++){
            char d[5], r[5];    int len;
            scanf("%s %s %d\n", d, r, &len);
            int did = 3000+getId(d), rid = getId(r);
            d2r[did] = rid;
            onRoad[rid].push_back(point(len, did));
            fromStart[did] = len;
        }
    }

    // onRoadのソート
    for(int i = 0; i < 1000; i++){
        if(onRoad[i].size())    sort(onRoad[i].begin(), onRoad[i].end());
    }

    // 車両用のグラフ (key : roadの端点(出発するroadの始点id))
    vector<int> car[2000];
    
    // 台車用のグラフ 有向
    vector<edge> cart[4000];

    // グラフcarの構築
    {
        for(int i = 0; i < crossNum; i++){
            int a = cross[i].first < 1000 ? cross[i].first+1000 : cross[i].first-1000;
            int b = cross[i].second;
            if(a >= 1000 && roadFlag[a-1000] == 1)  continue;
            if(b >= 1000 && roadFlag[b-1000] == 1)  continue;
            car[cross[i].first < 1000 ? cross[i].first+1000 : cross[i].first-1000].push_back(cross[i].second);
        }
    }

    // グラフcartの構築
    {
        // road・park・deliver
        for(int i = 0; i < 1000; i++){ // 道路id
            for(int j = 0; j+1 < onRoad[i].size(); j++){
                // if(onRoad[i][j].id==onRoad[i][j+1].id)  continue;
                cart[onRoad[i][j].id].push_back(edge(onRoad[i][j+1].id, onRoad[i][j+1].dist-onRoad[i][j].dist));
                cart[onRoad[i][j+1].id].push_back(edge(onRoad[i][j].id, onRoad[i][j+1].dist-onRoad[i][j].dist));
            }
        }
        // cross
        for(int i = 0; i < crossNum; i++){
            cart[cross[i].first].push_back(edge(cross[i].second, 0));
            cart[cross[i].second].push_back(edge(cross[i].first, 0));
        }
    }

    // クエリ処理
    for(int i = 0; i < queryNum; i++){
        int op;  char a[7], b[7];
        scanf("%d %s %s\n", &op, a, b);
        int from = getId(a), to = getId(b);
        if(a[0] == 'P'){
            from += 2000;
        }else if(a[0] == 'D'){
            from += 3000;
        }
        if(b[0] == 'P'){
            to += 2000;
        }else if(b[0] == 'D'){
            to += 3000;
        }

        vector<ll> dp(4000, LLONG_MAX);
        priority_queue<pair<ll,int>> q;

        if(op == 0){
            int frid = p2r[from];
            int trid = p2r[to];
            if(frid == trid && a[4] == b[4]){
                if(a[4] == 'S' && fromStart[to] >= fromStart[from]){
                    printf("%d\n", fromStart[to]-fromStart[from]);
                    continue;   // go to the next query
                }else if(a[4] == 'E' && fromStart[from] >= fromStart[to]){
                    printf("%d\n", fromStart[from]-fromStart[to]);
                    continue;   // go to the next query
                }
            }
            // まずは、自分が向いている方向に進んだとき最初に到達する道路の端点へ向かう
            ll ans = 0;
            if(a[4] == 'S')         ans += roadLen[frid]-fromStart[from];
            else if(a[4] == 'E')    ans += fromStart[from];
            // 同様のことを終点についても行う
            if(b[4] == 'S')         ans += fromStart[to];
            else if(b[4] == 'E')    ans += roadLen[trid]-fromStart[to];

            // from, startがまだ駐車箇所idのままなので、道路idへ変換する
            if(a[4] == 'S')         from = frid;            
            else if(a[4] == 'E')    from = frid+1000;       
            if(b[4] == 'S')         to = trid;
            else if(b[4] == 'E')    to = trid+1000;

            // 道路の端点のみに対するdijkstraを行う
            // 辺が特殊なので気を付ける
            for(int tmp : car[from]){
                if(dp[tmp] > 0){
                    dp[tmp] = 0;
                    q.push({-0, tmp});
                }
            }
            
            bool ok = false;
            while(!q.empty()){
                auto p = q.top();   q.pop();
                ll cost = -p.first, pos = p.second;
                if(dp[pos] != cost) continue;
                if(pos == to){
                    ok = true;
                    ans += dp[pos];
                    break;
                }
                ll ncost = cost + roadLen[pos < 1000 ? pos : pos-1000];
                for(int tmp : car[pos]){
                    if(dp[tmp] > ncost){
                        dp[tmp] = ncost;
                        q.push({-ncost, tmp});
                    }
                }
            }

            cout << (ok ? ans : -1) << endl;
        }else if(op == 1){
            // do simple dijkstra
            dp[from] = 0;
            q.push({-0, from});
            ll ans = -1;
            while(!q.empty()){
                auto p = q.top();   q.pop();
                ll cost = -p.first, pos = p.second;
                if(cost != dp[pos]) continue;
                if(pos == to){
                    ans = cost;
                    break;
                }
                for(edge e : cart[pos]){
                    ll ncost = cost + e.dist;
                    if(dp[e.to] > ncost){
                        dp[e.to] = ncost;
                        q.push({-ncost, e.to}); 
                    }
                }
            }
            cout << ans << endl;
        }

    }

    return 0;
}