// coding on smartphone
#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

int main()
{
    ll A[2], dp[2], next, tmp;
    int n;
    cin >> n;
    cin >> A[0] >> A[1];
    dp[0] = 0;
    dp[1] = abs(A[0] - A[1]);
    for (int i = 2; i < n; i++)
    {
        cin >> next;
        tmp = min(dp[0] + abs(next - A[0]), dp[1] + abs(next - A[1]));
        A[0] = A[1];
        A[1] = next;
        dp[0] = dp[1];
        dp[1] = tmp;
    }

    cout << dp[1] << endl;
    return 0;
}
