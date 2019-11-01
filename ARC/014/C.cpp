#include<iostream>
#include<list>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;
    list<char> l;
    for(char c : s){
        if(l.empty()){
            l.push_front(c);
        }else if(l.front() == c){
            l.pop_front();
        }else if(l.back() == c){
            l.pop_back();
        }else if(l.size() == 3){
            list<char> next;
            for(auto it = l.begin(); it != l.end(); it++){
                if(*it != c)    next.push_back(*it);
            }
            l = next;
        }else{
            l.push_back(c);
        }
    }
    cout << l.size() << endl;
    return 0;
}