---
title: Interval Segment Tree
documentation_of: ../../data-structure/IntervalSegTree.hpp
---

Interval Segment Tree（遅延セグ木）です。

## Declaration
```cpp
template <class T, class U, T (*nodef)(const T&, const T&), void (*lazyf)(U&, const U&), void (*updf)(T&, const U&, const unsigned int&)>
class IntervalSegTree : public SegTree<T, nodef>;
```

`T` は扱う要素の型を表します。`U` は値の更新時に適用する演算の対象の型を表します。`nodef` は要素同士に適用する演算を表します。`lazyf` は更新時に適用する演算を表します。`updf` は、区間内のすべての要素に `lazyf` を適用した際、すべての要素に `nodef` を適用した結果を元の結果から導出する演算を表します。

## Constructor
```cpp
IntervalSegTree(unsigned int m, T e_); // (1)
IntervalSegTree(unsigned int m, T init, T e_); // (2)
IntervalSegTree(const std::vector<T>& initvec, T e_); // (3)
```

#### (1)
長さ $m$, 単位元 `e_` の Interval Segment Tree を構築します。$O(m)$ で動作します。

#### (2)
長さ $m$, 単位元 `e_` の Interval Segment Tree を構築し、`init` で初期化します。$O(m)$ で動作します。

#### (3)
単位元 `e_` で初期状態 `initvec` をもつ Interval Segment Tree を構築します。$m$ を `initvec` の長さとして、$O(m)$ で動作します。

## Methods

### update
```cpp
void update(int i, U x); //(1)
void update(int l, int r, U x); //(2)
```

#### (1)
$i$ 番目の要素 `element` を `update(element, x)` で置き換えます。$O(\log m)$ で動作します。

#### (2)
$[l, r)$ に含まれるすべての要素 `element` について、それを `update(element, x)` で置き換えます。$O(\log m)$ で動作します。

### query
```cpp
T query(l, r);
```

$[l, r)$ に `nodef` を作用させた結果を返します。$O(\log m)$ で動作します。

### query_all
```cpp
T query_all();
```

全体に `nodef` を作用させた結果を返します。$O(1)$ で動作します。

### operator[]
```cpp
T operator[](const int& x);
```

$x$ 番目の要素を返します。$O(\log m)$ で動作します。

### max_right
```cpp
template <class F>
int max_right(int st, F check); // (1)
template <bool (*check)(const T&)>
int max_right(int st); // (2)
```

$[st, r)$ に `nodef` を作用させた結果が `check` を満たす最小の $r$ を返します。$O(\log m)$ で動作します。

### min_left
```cpp
template <class F>
int min_left(int st, F check); // (1)
template <bool (*check)(const T&)>
int min_left(int st); // (2)
```

$[l, st)$ に `nodef` を作用させた結果が `check` を満たす最大の $l$ を返します。$O(\log m)$ で動作します。

## Subclasses

### RAQRSQ
```cpp
template <class T>
class RAQRSQ : public IntervalSegTree<T, T, RAQRSQ_nodef, RAQRSQ_lazyf, RAQRSQ_updf>;
```

`RAQRSQ_nodef`, `RAQRSQ_lazyf` は加法を表します。

### RAQRMiQ
```cpp
template<class T>
class RAQRMiQ : public IntervalSegTree<T, T, RAQRMiQ_nodef, RAQRMiQ_lazyf, RAQRMiQ_updf>;
```

`RAQRMiQ_nodef` は `min` 演算を、`RAQRMiQ_lazyf` は加法を表します。

### RAQRMaQ
```cpp
template <class T>
class RAQRMaQ : public IntervalSegTree<T, T, RAQRMaQ_nodef, RAQRMaQ_lazyf, RAQRMaQ_updf>;
```

`RAQRMaQ_nodef` は `max` 演算を、`RAQRMaQ_lazyf` は加法を表します。

### RUQRSQ
```cpp
template <class T>
class RUQRSQ : public IntervalSegTree<T, T, RUQRSQ_nodef, RUQRSQ_lazyf, RUQRSQ_updf>;
```

`RUQRSQ_nodef` は加法を、`RUQRSQ_lazyf` は 2 つ目の引数をそのまま返す演算を表します。

### RUQRMiQ
```cpp
template <class T>
class RUQRMiQ : public IntervalSegTree<T, T, RUQRMiQ_nodef, RUQRMiQ_lazyf, RUQRMiQ_updf>;
```

`RUQRMiQ_nodef` は加法を、`RUQRMiQ_lazyf` は `min` 演算を表します。

### RUQRMaQ
```cpp
template <class T>
class RUQRMaQ : public IntervalSegTree<T, T, RUQRMaQ_nodef, RUQRMaQ_lazyf, RUQRMaQ_updf>;
```

`RUQRMaQ_nodef` は加法を、`RUQRMaQ_lazyf` は `max` 演算を表します。

### RChMiQRMiQ
```cpp
template <class T>
class RChMiQRMiQ : public IntervalSegTree<T, T, RChMiQRMiQ_nodef, RChMiQRMiQ_lazyf, RChMiQRMiQ_updf>;
```

`RChMiQRMiQ_nodef`, `RChMiQRMiQ_lazyf` は `min` 演算を表します。

### RChMaQRMaQ
```cpp
template <class T>
class RChMaQRMaQ : public IntervalSegTree<T, T, RChMaQRMaQ_nodef, RChMaQRMaQ_lazyf, RChMaQRMaQ_updf>;
```

`RChMaQRMaQ_nodef`, `RChMaQRMaQ_lazyf` は `max` 演算を表します。