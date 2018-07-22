#include<iostream>
#include<list>
using namespace std;

int main(){
    list<int> result;

    int n;
    cin >> n;

    int a;
    cin >> a;
    result.push_front(a);

    bool way = (n%2 == 0);
    for(int i = 1; i < n; i++){
        cin >> a;
        if(way) result.push_front(a);
        else    result.push_back(a);
        way = !way;
    }

    bool first = true;
    for(list<int>::iterator it = result.begin(); it != result.end(); it++){
        if(first)   first = false;
        else        cout << " ";
        cout << *it;
    }

    cout << endl;

    return 0;
}