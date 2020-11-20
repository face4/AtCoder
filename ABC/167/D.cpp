#include<iostream>
using namespace std;
typedef long long ll;

int bi[62][200000];

int main(){
    int n;
    ll k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)  cin >> bi[0][i], bi[0][i]--;
    for(int s = 1; s < 62; s++){
        for(int i = 0; i < n; i++){
            bi[s][i] = bi[s-1][bi[s-1][i]];
        }
    }
    int pos = 0;
    for(int s = 0; s < 62; s++){
        if(k>>s&1)  pos = bi[s][pos];
    }
    cout << pos+1 << endl;
    return 0;
}