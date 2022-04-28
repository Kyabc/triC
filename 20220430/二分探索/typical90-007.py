INF = 1 << 60

n = int(input())
a = list(map(int, input().split()))
q = int(input())

a.append(INF)
a.append(-INF)
a.sort()

for i in range(q):
    b = int(input())
    left, right = 0, n + 1
    while abs(left - right) > 1:
        mid = (left + right) // 2
        if a[mid] > b:
            right = mid
        else:
            left = mid
    val1 = a[right] - b
    val2 = b - a[left]
    print(min(val1, val2))