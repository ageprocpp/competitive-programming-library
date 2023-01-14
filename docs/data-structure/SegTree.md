---
title: Segment Tree
documentation_of: ../../data-structure/SegTree.hpp
---

## Declaration
```cpp
template <class T, T (*nodef)(const T&, const T&)>
class SegTree;
```

`T` は扱う要素の型、`nodef` は要素同士に適用する演算を表します。

## Constructor
```cpp
SegTree(T e_); // (1)
SegTree(unsigned int m_, T e_); // (2)
SegTree(unsigned int m_, T init, T e_); // (3)
template <class U>
SegTree(const std::vector<U>& initvec, T e_); // (4)
```

#### (1)
単位元 `e_` の Segment Tree を構築します。

#### (2)
長さ `m_`、単位元 `e_` の Segment Tree を構築し、`T()` で初期化します。$O(m\\_)$ で動作します。

#### (3)
長さ `m_`、単位元 `e_` の Segment Tree を構築し、`init` で初期化します。$O(m\\_)$ で動作します。

#### (4)
単位元 `e_` で初期状態 `initvec` をもつ Segment Tree を構築します。$m\\\_$ を `initvec` の長さとして、$O(m\\_)$ で動作します。

## Methods

### update
```cpp
void update(int i, T x);
```

$i$ 番目の要素を $x$ に変更します。$O(\log m\\_)$ で動作します。

### query
```cpp
T query(int l, int r) const;
```

$[l, r)$ に `nodef` を作用させた結果を返します。$O(\log m\\_)$ で動作します。

### query_all
```cpp
T query_all() const;
```

全体に `nodef` を作用させた結果を返します。$O(1)$ で動作します。

### operator[]
```cpp
const T& operator[](const int& x) const;
```

$i$ 番目の要素への `const` な参照を返します。$O(1)$ で動作します。

### fill
```cpp
void fill(T x);
```

全体を $x$ に変更します。$O(m\\_)$ で動作します。

### max_right
```cpp
template <class F>
int max_right(int st, F check) const; // (1)
template <bool (*check)(const T&)>
int max_right(int st) const; // (2)
```

$[st, r)$ に `nodef` を作用させた結果が `check` を満たす最小の $r$ を返します。$O(\log m\\_)$ で動作します。

### min_left
```cpp
template <class F>
int min_left(int st, F check) const; // (1)
template <bool (*check)(const T&)>
int min_left(int st) const; // (2)
```

$[l, st)$ に `nodef` を作用させた結果が `check` を満たす最大の $l$ を返します。$O(\log m\\_)$ で動作します。

## Subclasses

### RSQ
```cpp
template <typename T>
class RSQ : public SegTree<T, RSQ_nodef>;
```

`RSQ_nodef` は加法を表します。

### RMiQ
```cpp
template <typename T, typename U = void>
class RMiQ : public SegTree<T, RMiQ_nodef>; // (1)
template <typename T>
class RMiQ<T, std::enable_if_t<std::numeric_limits<T>::is_specialized, std::nullptr_t>> : public SegTree<T, RMiQ_nodef>; // (2)
```

`RMiQ_nodef` は `min` 演算を表します。
`T` が `std::numeric_limits` で特殊化された型の場合、その型の最大値を単位元とします。

### RMaQ
```cpp
template <typename T, typename U = void>
class RMaQ : public SegTree<T, RMaQ_nodef>; // (1)
template <typename T>
class RMaQ<T, std::enable_if_t<std::numeric_limits<T>::is_specialized, std::nullptr_t>> : public SegTree<T, RMaQ_nodef>; // (2)
```

`RMaQ_nodef` は `max` 演算を表します。
`T` が `std::numeric_limits` で特殊化された型の場合、その型の最小値を単位元とします。