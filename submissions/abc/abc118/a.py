from sys import stdin
A, B = [int(x) for x in stdin.readline().rstrip().split()]
if (B%A==0):
  print(A+B)
else:
  print(B-A)
