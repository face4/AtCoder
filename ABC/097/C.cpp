#include <iostream>
#include <set>
using namespace std;

int main()
{
    string s;
    int k;
    cin >> s >> k;
    set<string> subs;

    for(int i = 1; i <= min(k, (int)s.size()); i++){
        for(int j = 0; j <= s.size()-i; j++){
            subs.insert(s.substr(j,i));
        }
    }

    set<string>::iterator it = subs.begin();
    while(k-- > 1)  it++;
    cout << *it << endl;
    return 0;
}