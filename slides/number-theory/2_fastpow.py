def fastpow(x: int, n: int):
    ans = 1
    while n > 0:
        if n % 2 == 1:
            ans *= x
        x *= x
        n //= 2
    return ans


if __name__ == '__main__':
    x = 2
    n = 10
    print(fastpow(x, n))