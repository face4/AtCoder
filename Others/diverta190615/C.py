n = int(input())
a = [int(x) for x in input().split()]
a.sort(reverse=True)
add, sub = [a[0]], [a[-1]]
for i in range(1, n-1):
    if a[i] >= 0:
        add.append(a[i])
    else:
        sub.append(a[i])
res = []
it = len(add)-1
while it > 0:
    res.append([sub[-1],add[it]])
    sub[-1] -= add[it]
    it -= 1
it = len(sub)-1
while it >= 0:
    res.append([add[0],sub[it]])
    add[0] -= sub[it]
    it -= 1
print(add[0])
print("\n".join([" ".join(map(str,x)) for x in res]))