def eratosthenes(n: int) -> list[bool]:
    if n < 2:
        n = 1
    prime = [True] * (n+1)
    prime[0] = prime[1] = False
    for i in range(2, n+1):
        if not prime[i]:
            continue
        for j in range(i+i, n + 1, i):
            prime[j] = False
    return prime


if __name__ == '__main__':
    n = 10
    prime = eratosthenes(n)
    for i in range(n+1):
        print(i, prime[i])
