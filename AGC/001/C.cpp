#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> v[n];
    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int ans = 1<<30;
    if(k%2){
        for(int i = 0; i < n; i++){
            for(int j : v[i]){
                int cnt = 2;
                queue<int> q;
                vector<int> d(n, 1<<30);
                d[i] = d[j] = 0;
                q.push(i);  q.push(j);
                while(!q.empty()){
                    int x = q.front();  q.pop();
                    if(d[x] == k/2) continue;
                    for(int next : v[x]){
                        if(d[next] != 1<<30)    continue;
                        d[next] = d[x]+1;
                        cnt++;
                        q.push(next);
                    }   
                }
                ans = min(ans, n-cnt);
            }
        }
    }else{
        for(int i = 0; i < n; i++){
            int cnt = 1;
            queue<int> q;
            vector<int> d(n, 1<<30);
            d[i] = 0;
            q.push(i);
            while(!q.empty()){
                int x = q.front();  q.pop();
                if(d[x] == k/2) continue;
                for(int next : v[x]){
                    if(d[next] != 1<<30)    continue;
                    d[next] = d[x]+1;
                    cnt++;
                    q.push(next);
                }
            }
            ans = min(ans, n-cnt);
        }
    }
    cout << ans << endl;
    return 0;
}