li = [int(i) for i in input().split()]
a = [1,9,7,4]

for x in a:
    if x not in li:
        print("NO")
        quit()

print("YES")