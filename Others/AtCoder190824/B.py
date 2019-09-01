n, k = map(int, input().split())
a = [int(x) for x in input().split()]
mod = 1000000007

ans = 0
for i in range(n):
    cnt,tmp = 0,0
    for j in range(i+1, n):
        if a[i] > a[j] : cnt+=1
    for j in range(0, n):
        if a[i] > a[j] : tmp+=1
    ans += (2*cnt + (k-1)*tmp)*k//2
    ans %= mod

print(ans)