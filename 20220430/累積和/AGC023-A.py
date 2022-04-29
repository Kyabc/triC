n = int(input())
a = list(map(int, input().split()))

s = [0 for i in range(n + 1)]
for i in range(n):
    s[i + 1] = s[i] + a[i]

ans = 0
counter = dict()
for i in range(n + 1):
    if s[i] not in counter:
        counter[s[i]] = 0
    ans += counter[s[i]]
    counter[s[i]] += 1

print(ans)