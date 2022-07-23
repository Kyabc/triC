#include <cstddef>
#include <cstdint>
#include <vector>
#include <cassert>

class union_find {
public:
    using size_type = std::size_t;
    using value_type = std::int_fast32_t;
protected:
    size_type _size;
    std::vector<value_type> _parent;
public:
    union_find() = default;
    union_find(size_type n): _size(n), _parent(n, value_type(-1)) { }

    void assign(size_type n) {
        _size = n;
        _parent.assign(n, value_type(-1));
    }

    void clear() {
        _size = 0;
        _parent.clear();
    }

    size_type root(size_type x) {
        assert(size_type(0) <= x and x < _parent.size());
        if (_parent[x] < 0) return x;
        return _parent[x] = static_cast<value_type>(root(_parent[x]));
    }

    size_type size() {
        return _size;
    }

    size_type size(size_type x) {
        assert(size_type(0) <= x and x < _parent.size());
        return static_cast<size_type>(-_parent[root(x)]);
    }

    bool same(size_type x, size_type y) {
        return root(x) == root(y);
    }

    bool unite(size_type x, size_type y) {
        size_type r_x = root(x), r_y = root(y);
        if (r_x == r_y) return false;
        if (_parent[r_x] > _parent[r_y]) std::swap(r_x, r_y);
        _parent[r_x] += _parent[r_y];
        _parent[r_y] = r_x;
        _size--;
        return true;
    }

};