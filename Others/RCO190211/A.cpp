// 移動距離の総和の最小化のみ考慮
#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<random>
#include<chrono>
#include<cfloat>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define x first
#define y second

int n;
vector<pair<pii,int>> v;
vector<int> d;
double score, ave;

void input(){
    cin >> n;
    v.resize(n);
    d.resize(n);
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        v[i] = {{a,b},i};
    }  
}

bool compx(pair<pii,int> a, pair<pii,int> b){
    pii aa = a.first, bb = b.first;
    if(aa.x != bb.x)    return aa.x < bb.x;
    else                return aa.y < bb.y;
}

bool compy(pair<pii,int> a, pair<pii,int> b){
    pii aa = a.first, bb = b.first;
    if(aa.y != bb.y)    return aa.y < bb.y;
    else                return aa.x < bb.x;
}

void answer(){
    for(int i = 0; i < n; i++)  cout << v[i].second << endl;
}

// distance between city-i and city-j (based on v)
int dist(int i, int j){
    return (v[i].first.x-v[j].first.x)*(v[i].first.x-v[j].first.x) + 
           (v[i].first.y-v[j].first.y)*(v[i].first.y-v[j].first.y);
}

void initcalc(){
    int sum = 0;
    for(int i = 0; i < n; i++){
        d[i] = dist(i, (i+1)%n);
        sum += d[i];
    }
    ave = (double)(sum) / n;
    score = 0;
    for(int i = 0; i < n; i++)  score += (d[i]-ave)*(d[i]-ave);
}

void updatescore(){

}

double calc(){
    int sum = 0;
    for(int i = 0; i < n; i++){
        d[i] = dist(i, (i+1)%n);
        sum += d[i];
    }
    ave = (double)(sum) / n;
    double ret = 0;
    for(int i = 0; i < n; i++)  ret += (d[i]-ave)*(d[i]-ave);
    return ret;
}


void challenge(int i, int j){
    swap(v[i], v[j]);
    double t = calc();
    if(t > score){
        swap(v[i], v[j]);
    }else{
        score = t;
    }
    // int diff =  -dist(i, (i+1)%n) - dist((i-1+n)%n, i) 
    //             -dist(j, (j+1)%n) - dist((j-1+n)%n, j) 
    //             +dist(j, (i+1)%n) + dist((i-1+n)%n, j) 
    //             +dist(i, (j+1)%n) + dist((j-1+n)%n, i);
    // if(diff > 0)    return;

    // // good! swap
    // ave -= (double)(diff)/n;
    // swap(v[i], v[j]);
    // d[i] = dist(i, (i+1)%n), d[j] = dist(j, (j+1)%n);
    // //updatescore();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    input();

    auto start = std::chrono::system_clock::now(); 
    random_device rnd;
    mt19937 mt(rnd());
    uniform_int_distribution<int> rand200(0, n-1);
    uniform_real_distribution<double> rdd(0.0, 1.0);

    initcalc();
    sort(v.begin(), v.end(), compx);

    double T = 2000.0;
    double T_END = 15.0;
    double T_FACTOR = 0.995;

    while(true){
        auto now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()-start).count();
        if(now > 1992)  break;
        int i = rand200(mt);
        int j = rand200(mt);
        if(abs(i-j) == 1)   continue;
        
        swap(v[i], v[j]);
        double t = calc();
        
        if(t < score || rdd(mt) < 1 + (double)(score-t)/T){
            score = t;
        }else{
            swap(v[i], v[j]);
        }

        T *= T_FACTOR;

    }

    answer();

	return 0;
}