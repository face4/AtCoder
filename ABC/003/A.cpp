#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int sum = n * (n + 1) / 2;

    double ans = (double)sum * 10000 / n;
    cout << fixed << setprecision(7) << ans << endl;

    return 0;
}
