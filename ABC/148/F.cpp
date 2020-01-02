#include<iostream>
#include<vector>
#include<set>
#include<queue>
using namespace std;

vector<int> v[100000], d(100000);
vector<bool> vis(100000, 0);

void dfs(int x, int dep){
    d[x] = dep;
    vis[x] = true;
    for(int y : v[x]){
        if(!vis[y]) dfs(y, dep+1);
    }
}

int main(){
    int n, a, b;
    cin >> n >> a >> b;
    a--, b--;
    for(int i = 0; i < n-1; i++){
        int x, y;
        cin >> x >> y;
        x--, y--;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(a, 0);
    set<int> dist[n+5];
    for(int i = 0; i < n; i++)  if(i != b)  dist[d[i]].insert(i);
    int ans = 0;
    vector<bool> no(n, 0);
    queue<int> aoki;
    aoki.push(b);
    no[b] = true;
    set<int> even, odd;
    even.insert(a);
    while(true){
        // cout << ans << endl;
        // cout << "even ";
        // for(int x : even)   cout << x << " ";
        // cout << endl;
        // cout << "odd ";
        // for(int x : odd)   cout << x << " ";
        // cout << endl;

        for(int x : dist[ans+1]){
            if(no[x]) continue;
            if((ans+1)%2==0)    even.insert(x);
            else                odd.insert(x);
        }

        bool judge = false;
        if((ans+1)%2 == 0)  judge = even.empty();
        else                judge = odd.empty();
        if(judge){
            cout << ans << endl;
            return 0;
        }
        ans++;
        queue<int> naoki;
        while(!aoki.empty()){
            int x = aoki.front();   aoki.pop();
            for(int next : v[x]){
                if(no[next])  continue;
                no[next] = true;
                naoki.push(next);
                if(d[next]%2 == 0)   even.erase(next);
                else                 odd.erase(next);
            }
        }
        if(ans%2 == 1)      judge = odd.empty();
        else                judge = even.empty();
        if(judge){
            cout << ans << endl;
            return 0;
        }
        aoki = naoki;
    }
}