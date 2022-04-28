INF = (1 << 60)
MAX = 1000100

def f(a, b):
    return a * a * a + a * a * b + a * b * b + b * b * b

n = int(input())
ans = INF

for a in range(MAX):
    ok, ng = MAX, -1
    while abs(ok - ng) > 1:
        mid = (ok + ng) // 2
        if (f(a, mid) >= n):
            ok = mid
        else:
            ng = mid
    ans = min(ans, f(a, ok))

print(ans)