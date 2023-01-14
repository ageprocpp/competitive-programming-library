---
title: Convex Hull Trick
documentation_of: ../../data-structure/ConvexHullTrick.hpp
---

一次関数の集合を管理し、ある $x$ での最小値/最大値を求めます。

## Declaration
```cpp
template<class T, bool isMin>
class ConvexHullTrick
```

`T` は関数の傾きと切片の型を表します。
`isMin` が `true` の場合最小値を、`false` の場合最大値を求めます。

## Constructor
```cpp
ConvexHullTrick() = default;
```

$O(1)$ で動作します。

## Methods

### addLine
```cpp
void addLine(T m, T b);
```

一次関数 $y=mx+b$ を追加します。集合の含む直線の数を $N$ として $O(\log N)$ で動作します。

### query
```cpp
std::pair<T, int> query(T x) const;
```

ある $x$ での最小値/最大値と、その関数の index を返します。

### clear
```cpp
void clear();
```

集合を空にします。index は $0$ に戻ります。