def ng(a):
    b = []
    for x in a:
        two = 0
        while x%2 == 0:
            x //= 2
            two += 1
        b.append(two)
    return sum(b) != b[0]*len(b)

def gcd(a, b):
    return a if b == 0 else gcd(b, a%b)

def lcm(a, b):
    return a//gcd(a,b)*b

def fail():
    print(0)
    exit(0)

n, m = map(int, input().split())
a = [int(x)//2 for x in input().split()]

if ng(a):
    fail()

lc = 1
for x in a:
    lc = lcm(lc, x)
    if lc > m:
        fail()

ret = 1
m -= lc
ret += m//(2*lc)
print(ret)
