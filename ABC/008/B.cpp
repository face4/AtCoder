#include<iostream>
#include<map>
using namespace std;

int main(){
    map<string, int> dict;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        dict[s]++;
    }

    int maxVote = -1;
    string ans = "";
    for(map<string,int>::iterator it = dict.begin(); it != dict.end(); it++){
        if((*it).second > maxVote){
            maxVote = (*it).second;
            ans = (*it).first;
        }
    }

    cout << ans << endl;
    return 0;
}