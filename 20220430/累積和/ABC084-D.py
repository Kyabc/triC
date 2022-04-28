def prime(x):
    """
    素数判定

    parameters
    ----------
    x : int
        素数判定したい整数
    
    returns
    ----------
    x が素数であれば True, そうでないなら False
    """
    if x < 2:
        return False
    if x == 2:
        return True
    i = 2
    while i * i <= x:
        if x % i == 0:
            return False
        i += 1
    return True

N = 100100

q = int(input())

a = [0 for i in range(N)]      # a[i] := i が 2017 に似ているなら 1, そうでないなら 0
for i in range(N):
    if i % 2 == 1 and prime(i) and prime((i + 1) // 2):
        a[i] = 1

# 前処理
s = [0 for i in range(N + 1)]  # a の累積和
for i in range(N):
    s[i + 1] = s[i] + a[i]

# クエリ
for i in range(q):
    l, r = map(int, input().split())
    print(s[r + 1] - s[l])
