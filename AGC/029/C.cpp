/*
必要な文字の種類は最大でもN.最小で1(文字列の長さが狭義短調増加のとき).
文字の種類数を決めたときに辞書順が成り立つように文字列群を構成できるか
をO(N)で判定することが出来れば、log(N)*O(N)の二分探索で解けるはず.
*/
#include<iostream>
#include<map>
#include<vector>
using namespace std;

int n;
vector<int> v;

bool check(int mid){
    map<int,int> len;
    //int from = n+1;

    for(int i = 1; i < n; i++){
        if(v[i-1] < v[i])   continue;

        int b = v[i];
        // 最悪O(N)
        while(len.count(b) && len[b] == mid-1 && b >= 1)    b--;
        if(b == 0)  return false;

        len[b]++;
        
        // TLEしそう O(log(len.size()) + O(len.end()-it))
        auto it = len.upper_bound(b);
        if(it != len.end())   len.erase(it, len.end());
    }

    return true;
}

int main(){
    cin >> n;
    
    v.resize(n);
    for(int i = 0; i < n; i++)  cin >> v[i];

    bool asc = true;
    for(int i = 1; i < n; i++)  asc &= v[i-1] < v[i];
    if(asc){
        cout << 1 << endl;
        return 0;
    }

    // (l, r]
    int l = 1, r = n;
    while(r-l > 1){
        int mid = (l+r)/2;
        if(check(mid))  r = mid;
        else            l = mid+1;
    }

    if(l != 1 && check(l))  cout << l << endl;
    else                    cout << r << endl;

    return 0;
}