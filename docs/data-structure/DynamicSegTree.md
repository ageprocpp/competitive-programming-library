---
title: Dynamic Segment Tree
documentation_of: ../../data-structure/DynamicSegTree.hpp
---

Segment Tree で必要な部分だけ追加的にメモリを確保してメモリ使用量を抑えます。

## Declaration
```cpp
template <class T, T (*nodef)(const T&, const T&), T (*ident)(), T (*init)() = ident>
class DynamicSegTree;
```

`T` は扱うデータの型、`nodef` は扱う演算、`ident` は `nodef` の単位元、`init` は各要素の初期値を扱います。
`nodef` は結合法則を満たす必要があります。

## Constructor
```cpp
DynamicSegTree(lint m);
```

長さ $m$ の Segment Tree を構築します。

## Methods

### update
```cpp
void update(lint i, T x);
```

$i$ 番目の要素を $x$ に変更します。$O(\log m)$ で動作します。

### query
```cpp
T query(lint a, lint b);
```

$[l, r)$ に `nodef` を作用させた結果を返します。$O(\log m)$ で動作します。

### operator[]
```cpp
const T& operator[](const lint& x);
```

$x$ 番目の要素への `const` な参照を返します。$O(\log m)$ で動作します。