r, b = map(int, input().split())
x, y = map(int, input().split())

def f(k):
    if r < k or b < k:
        return False
    flower1 = (r - k) // (x - 1)
    flower2 = (b - k) // (y - 1)
    return flower1 + flower2 >= k

ok, ng = 0, r + b
while abs(ok - ng) > 1:
    mid = (ok + ng) // 2
    if f(mid):
        ok = mid
    else:
        ng = mid

print(ok)