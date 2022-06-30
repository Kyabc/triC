# n の値を自由に変えて試してみてください
# n が大きすぎると時間内に終わらない可能性があります
n = 20

counter_naive = 0
counter_memo = 0
memo = []

def fibonacci_naive(n):
    global counter_naive
    counter_naive += 1
    if n <= 2:
        return 1
    else:
        return fibonacci_naive(n-1) + fibonacci_naive(n-2)

def fibonacci_memo(n):
    global counter_memo
    global memo
    counter_memo += 1
    if memo[n] != -1:
        return memo[n]
    elif n <= 2:
        return 1
    else:
        memo[n] = fibonacci_memo(n-1) + fibonacci_memo(n-2)
        return memo[n]

assert 0 < n
print('再帰関数の呼び出し回数')
print('  n  |  naive  |  memo ')
for i in range(1, n + 1):
    counter_naive = 0
    counter_memo = 0
    memo = [-1] * (i + 1)
    fibonacci_naive(i)
    fibonacci_memo(i)
    print(str(i).ljust(4), '|', str(counter_naive).ljust(7), '|', str(counter_memo).ljust(6))