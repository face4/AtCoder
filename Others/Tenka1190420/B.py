n = int(input())
s = list(input())
k = int(input())
print("".join(list(map(lambda x: "*" if x!=s[k-1] else x, s))))