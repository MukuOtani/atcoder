T = [0] * 5
N = int(input())
for i in range(5):
	t = int(input())
	T[i] = t

if N%min(T) == 0:
	rissoku = N//min(T)-1
else:
	rissoku = N//min(T)

ans = rissoku + 5
print(ans)
