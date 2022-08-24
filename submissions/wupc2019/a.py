s = list(input())
i = 0
while i < len(s)-1:
    if s[i] == 'W' and s[i+1] == 'A':
        s[i] = 'A'
        s[i+1] = 'C'
        i = max(0, i-2)
    elif s[i+1] == 'W':
    	i += 1
    else:
        i += 2

for j in range(len(s)):
    print(s[j], end='')
