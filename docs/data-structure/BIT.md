---
title: Binary Indexed Tree
documentation_of: ../../data-structure/BIT.hpp
---

Binary Indexed Tree (Fenwick Tree) です。
数列の区間和が高速に求められます。

## Declaration

```cpp
template<class T>
class BIT;
```

`T` は扱うデータの型を表します。

## Constructor

```cpp
BIT(int n);
```

`n` は扱う配列の長さを表します。$O(1)$ で動作します。

## Methods

### add

```cpp
void add(int a, T x);
```

index が `a` の位置に `x` を加算します。$O(\log n)$ で動作します。

### query

```cpp
T query(int l, int r) const;
```

$[l, r)$ の総和を返します。$O(\log n)$ で動作します。

### clear

```cpp
void clear();
```

全体を $0$ で初期化します。$O(n)$ で動作します。

### lower_bound

```cpp
int lower_bound(T x) const;
```

`query(0, r)` $ >= x$ となる最小の x を返します。$O(\log n)$ で動作します。

### upper_bound

```cpp
int upper_bound(T x) const;
```

`query(0, r)` $ > x$ となる最小の x を返します。$O(\log n)$ で動作します。