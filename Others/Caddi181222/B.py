n, h, w = map(int, input().split())
print(len(list(filter(lambda x:int(x[0])>=h and int(x[1])>=w, [input().split() for i in range(n)]))))
