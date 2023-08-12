class SegmentTree:
    def __init__(self, size: int, op, e) -> None:
        """
        Params:
            size: int
                配列のサイズ
            op: function
                二項演算
            e: Any
                単位元
        """
        self.op = op
        self.e = e
        # n 以上の最小の 2 冪を探す
        n = 1
        while n < size:
            n *= 2
        
        # 二分木のサイズは 2N
        self.n = n
        self.a = [e for i in range(n * 2)]

    def update(self, i, x) -> None:
        # i をセグ木上の番号に直す
        i += self.n
        # i 番目を更新
        self.a[i] = x
        # 親を辿りながら更新
        i //= 2
        while i > 0:
            self.a[i] = self.op(self.a[i * 2], self.a[i * 2 + 1])
            i //= 2

    # [l, r)
    def find(self, l, r) -> int:
        return self._find(l, r, 1, 0, self.n)

    def _find(self, l, r, i, a, b) -> int:
        """
        find(l, r)
        今見ているノード番号が i
        今見ているノードが担当している範囲が [a, b)
        """
        # 今見ている区間がクエリから完全に外れている時
        if r <= a or b <= l:
            return self.e
        # 今見ている区間が完全にクエリに含まれるとき
        if l <= a and b <= r:
            return self.a[i]
        # 今見ている区間が一部だけクエリに含まれるとき
        left_value = self._find(l, r, i * 2, a, (a + b) // 2)
        right_value = self._find(l, r, i * 2 + 1, (a + b) // 2, b)
        return self.op(left_value, right_value)

    def at(self, i):
        return self.a[i + self.n]


def plus(a, b):
    return a + b

if __name__ == "__main__":
    n, q = map(int, input().split())

    # セグ木の宣言
    segtree = SegmentTree(n, plus, 0)

    for _ in range(q):
        com, x, y = map(int, input().split())
        # update(x, y)
        if com == 0:
            a_i = segtree.at(x-1)
            segtree.update(x-1, a_i + y)
        # find(x, y)
        else:
            ans = segtree.find(x-1, y)
            print(ans)

"""
    op: min
    e: INF
    min(10, INF) = 10
    min(998244353, INF) = 998244353
    
    op: max
    e: -INF
    
    op: sum
    e: 0
    
    op: prod
    e: 1
    
    op: gcd
    e: 0
    
    op: lcm
    e: 1
"""