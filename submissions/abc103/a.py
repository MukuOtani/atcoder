from sys import stdin
A = [int(x) for x in stdin.readline().rstrip().split()]

print(max(A)-min(A))
