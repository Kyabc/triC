def is_prime(x):
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