def divisor(n: int) -> list[int]:
    assert(n >= 0)
    div = []
    x = 1
    while x * x <= n:
        if n % x == 0:
            div.append(x)
            if n != n // x:
                div.append(n // x)
        x += 1
    return div


if __name__ == '__main__':
    n = 12345
    for x in divisor(n):
        print(x)
    #> 1,12345,3,4115,5,2469,15,823