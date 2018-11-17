#include<iostream>
#include<map>
using namespace std;

int main(){
    int n;
    cin >> n;
    map<string, int> ma;
    map<int, string> mb;
    ma["Sat"] = 0;  mb[0] = "Sat";
    ma["Sun"] = 1;  mb[1] = "Sun";  
    ma["Mon"] = 2;  mb[2] = "Mon";
    ma["Tue"] = 3;  mb[3] = "Tue";
    ma["Wed"] = 4;  mb[4] = "Wed";
    ma["Thu"] = 5;  mb[5] = "Thu";
    ma["Fri"] = 6;  mb[6] = "Fri";

    string s;
    while(n-- > 0){
        cin >> s;
        cout << mb[(ma[s]+1)%7] << endl;
    }

    return 0;
}