#include<iostream>
#include<vector>
#include<random>
#include<algorithm>
#include<set>
using namespace std;
#define inRange(x,a,b) (a <= x && x <= b)

int N, K;

struct exec{
    int i, j, k, l, v;
    exec() {}
    exec(int i, int j, int k, int l, int v) : i(i), j(j), k(k), l(l), v(v) {}
    void print() {printf("%d %d %d %d %d\n", i, j, k, l, v);}
};

vector<exec> ans;
int score = 900000000;

int calcScore(vector<int> &v){
    int ret = 0;
    for(int i = 0; i < N; i++)   ret += abs(v[i]-(i+1));
    return ret;
}

vector<int> getDiff(vector<int> v, int &minpos, int &maxpos){
    int minval = 30000, maxval = -30000;
    vector<int> ret(N);
    for(int i = 0; i < N; i++){
        ret[i] = v[i]-(i+1);
        if(ret[i] < minval) minval = ret[i], minpos = i;
        if(ret[i] > maxval) maxval = ret[i], maxpos = i;
    }
    return ret;
}

void answer(){
    for(int i = 0; i < K; i++)  ans[i].print();
}

bool check(int a, int b, int c){
    if(a >= 0 && b >= 0 && c >= 0)  return true;
    if(a <= 0 && b <= 0 && c <= 0)  return true;
    return false;
}

int main(){
    random_device rnd;
    mt19937 mt(rnd());
    uniform_int_distribution<int> rand30k(0,29997);

    cin >> N >> K;

    vector<int> v(N);
    for(int i = 0; i < N; i++)  cin >> v[i];

    if(calcScore(v) == 0){
        exec no(1,1,2,2,0);
        for(int i = 0; i < K; i++)  no.print();
        return 0;
    }

    int minpos, maxpos;
    for(int i = 0; i < K; i++){
        vector<int> diff = getDiff(v, minpos, maxpos);

        int da = 1, db = 4, de = 0, loop = 0;
        while(loop < 2500){
            int a, b;
            while(a = rand30k(mt)){
                if(diff[a] > 0 && check(diff[a], diff[a+1], diff[a+2]))  break;
            }

            while(b = rand30k(mt)){
                // set<int> x;
                // x.emplace(a); x.emplace(a+1); x.emplace(a+2);
                // x.emplace(b); x.emplace(b+1); x.emplace(b+2);
                
                // so ugly
                bool indep = (a != b) && (a+1 != b) && (a+2 != b) &&
                                (a != b+1) && (a+1 != b+1) && (a+2 != b+1) && 
                                    (a != b+2) && (a+1 != b+2) && (a+2 != b+2);

                if(diff[b] < 0 && indep && check(diff[b],diff[b+1],diff[b+2])) break;
            }
            
            int wantToDec = min( min({diff[a], diff[a+1], diff[a+2]}) , 
                                min({v[a],v[a+1],v[a+2]})-1 );
            int wantToInc = min( min({abs(diff[b]),abs(diff[b+1]),abs(diff[b+2])}) , 
                                min({30000-v[b],30000-v[b+1],30000-v[b+2]}) );
            
            int e = min(wantToDec, wantToInc);

            if(e > de){
                da = a, db = b, de = e;
            }
            loop++;
        }

        // apply
        v[da] -= de, v[da+1] -= de, v[da+2] -= de;
        v[db] += de, v[db+1] += de, v[db+2] += de;
        ans.push_back(exec(da+1,da+3,db+1,db+3,de));
        
        /*
        int val = min(diff[maxpos], -diff[minpos]);
        ans.push_back(exec(maxpos+1,maxpos+1,minpos+1,minpos+1,val));
        v[maxpos] -= val;
        v[minpos] += val;
        */
    }

    answer();

    return 0;
}