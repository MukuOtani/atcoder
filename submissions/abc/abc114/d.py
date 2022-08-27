N = int(input())
a = [0] * (N+1)

for i in range(2, N+1):
	# N‚Ü‚Å‚Ì—v‘f‚É‚Â‚¢‚Ä‡‚Éˆö”•ª‰ğ‚µ‚Ä‚¢‚­
	cnt = i
	for j in range(2, i+1):
		# ‚Ğ‚½‚·‚çj‚Åˆö”•ª‰ğ‚µ‚ÄAj‚É‚Â‚¢‚Ä‚Ìw”‚ğ‹‚ß‚é
		while cnt%j == 0:
			a[j] += 1
			cnt //=j

def num(m):
	ret = 0
	for i in range(2, N+1):
		if a[i] >= m:
			ret += 1
	return ret

ans = 0
ans += num(74)
ans += num(24)*(num(2)-1)
ans += num(14)*(num(4)-1)
ans += num(4)*(num(4)-1)*(num(2)-2)//2
print(ans)
