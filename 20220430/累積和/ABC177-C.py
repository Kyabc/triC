MOD = 1000000007

n = int(input())
a = list(map(int, input().split()))

s = [0 for i in range(n + 1)]
for i in range(n):
    s[i + 1] = (s[i] + a[i]) % MOD

ans = 0
for i in range(n):
    ans += a[i] * (s[n] - s[i + 1])
    ans %= MOD

print(ans)