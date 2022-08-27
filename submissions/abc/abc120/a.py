from sys import stdin
A, B, C = [int(x) for x in stdin.readline().rstrip().split()]
if C <= B//A:
  print(C)
else:
  print(B//A)
