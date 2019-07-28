n = int(input())
a = [0] + list(map(int, input().split()))
ans = [0]*(n+1)
for i in range(n, n//2, -1) : ans[i] = a[i]
for i in range(n//2, 0, -1) :
    tmp = 0
    for j in range(i+i, n+1, i) : tmp += ans[j]
    ans[i] = (tmp+a[i])%2
print(sum(ans))
for i in range(1, n+1) : ans[i] *= i
print(" ".join(map(str, list(filter(lambda x:x!=0, ans)))))