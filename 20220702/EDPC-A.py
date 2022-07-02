INF = float('inf')

n = int(input())
h = list(map(int, input().split()))

dp = [INF for i in range(n)]
dp[0] = 0
dp[1] = dp[0] + abs(h[0] - h[1])

for i in range(2, n):
    dp[i] = min(dp[i-1] + abs(h[i-1] - h[i]), dp[i-2] + abs(h[i-2] - h[i]))

print(dp[n-1])