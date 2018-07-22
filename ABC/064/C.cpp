#include<iostream>
using namespace std;

int classify(int rate){
    if(rate < 400)  return 0;
    if(rate < 800)  return 1;
    if(rate < 1200)  return 2;
    if(rate < 1600)  return 3;
    if(rate < 2000)  return 4;
    if(rate < 2400)  return 5;
    if(rate < 2800)  return 6;
    if(rate < 3200)  return 7;
}

int main(){
    int n;
    cin >> n;

    bool color[8] = {};

    int a, wild = 0;
    for(int i = 0; i < n; i++){
        cin >> a;
        if(a >= 3200)   wild++;
        else            color[classify(a)] = true;
    }

    int ans = 0;
    for(int i = 0; i < 8; i++)  if(color[i])    ans++;

    cout << max(ans, 1) << " " << ans + wild << endl;
    
    return 0;
}