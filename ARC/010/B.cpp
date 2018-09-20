#include<iostream>
using namespace std;

int days[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int mdTodays(int m, int d){
    int ret = 0;
    for(int i = 1; i < m; i++)  ret += days[i];
    ret += d;
    return ret;
}

int main(){
    bool isHoliday[368] = {};
    for(int i = 1; i <= 366; i++){
        if((i%7) <= 1)    isHoliday[i] = true;
    }

    int n, m, d;
    scanf("%d\n", &n);
    for(int i = 0; i < n; i++){
        scanf("%d/%d\n", &m, &d);
        int x = mdTodays(m, d);
        while(x <= 366 && isHoliday[x])    x++;
        if(x <= 366)    isHoliday[x] = true;
    }

    int ans = 0;
    for(int i = 1; i <= 366; i++){
        if(isHoliday[i]){
            int tmp = 0;
            while(isHoliday[i]){
                tmp++;
                i++;
            }
            ans = max(ans, tmp);
        }
    }

    cout << ans << endl;

    return 0;
}