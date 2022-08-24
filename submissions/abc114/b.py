from sys import stdin
S = input()

ans = 10**9
for i in range(len(S)-2):
    ans = min(abs(int(S[i:i+3])-753), ans)
print(ans)
