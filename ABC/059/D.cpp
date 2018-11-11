/*解説AC.必勝パターンを定式化出来ないかと色々考えたものの、うまく思いつかなかった.
操作のたびに全体の石の数は減少する.Nimのイメージで"上手く操作をすれば状態AからBに必ず
遷移させることが出来る、かつBからはどうあがいてもAに転んでしまう。さらにAないしBが必勝・
必敗状態である"という条件を満たす状態の抽出に対する感性を研ぎ澄ましていく必要がある.(?)*/
#include<iostream>
using namespace std;

int main(){
    long long x, y;
    cin >> x >> y;
    cout << (abs(x-y) <= 1 ? "Brown" : "Alice") << endl;
    return 0;
}