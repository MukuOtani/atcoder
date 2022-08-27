from sys import stdin

def f(num):
  d = []
  if num != 1:
    for i in range(1,num):
      if num % i == 0:
    	  d.append(i)
      d.append(num)
  else:
      d = [1]
  return d

A, B, C = [int(x) for x in stdin.readline().rstrip().split()]
a = f(A)
b = f(B)
d = set(a)&set(b)
d = sorted(list(d),reverse=True)
print(d[C-1])
