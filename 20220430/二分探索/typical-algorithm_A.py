n, k = map(int, input().split())
a = list(map(int, input().split()))

# 条件を満たす i が存在しない場合
if a[-1] < k:
    print(-1)
    exit()

# 二分探索
left, right = -1, n - 1
while abs(right - left) > 1:
    mid = (right + left) // 2
    if a[mid] < k:
        left = mid
    else:
        right = mid

print(right)