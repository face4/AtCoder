mod = 1000000007
for i in range(10775):
    a, b = map(int, input().split())
    print("v[{0}]={1};".format(i, b%mod))