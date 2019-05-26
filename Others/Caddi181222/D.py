n = int(input())
print("second" if all([int(input())%2==0 for i in range(n)]) else "first")