#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, a;
    string k;
    cin >> n >> a >> k;
    a--;
    vector<int> b(n);
    for(int i = 0; i < n; i++)  cin >> b[i], b[i]--;
    vector<bool> visit(n, 0);
    vector<int> v;
    while(!visit[a]){
        visit[a] = true;
        v.push_back(a);
        a = b[a];
    }
    vector<int> x;
    int fir;
    for(fir = 0; fir < v.size(); fir++){
        if(v[fir] == a) break;
        x.push_back(v[fir]);
    }
    v.erase(v.begin(), v.begin()+fir);
    int loop = v.size();
    if(k.length() < 8 && stoi(k) <= fir){
        cout << b[x[stoi(k)-1]]+1 << endl;
        return 0;
    }
    int acc = 0;
    for(int i = 0; i < k.length(); i++){
        acc = acc*10 + (k[i]-'0');
        acc %= loop;
    }
    acc -= fir;
    acc--;
    if(acc < 0) acc += (-acc/loop+1)*loop;
    acc %= loop;
    cout << b[v[acc]]+1 << endl;
    return 0;
}