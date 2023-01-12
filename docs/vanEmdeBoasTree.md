---
title: van Emde Boas Tree
documentation_of: ../data-structure/vanEmdeBoasTree.hpp
---

整数の集合を高速に扱うデータ構造です。

## Declaration

```cpp
template<uint bit>
class vanEmdeBoasTree;
```

`bit` は扱う整数のビット幅を表し、$1\leq$ `bit` $< 32$ である必要があります。

## Constructor

```cpp
vanEmdeBoasTree() = default;
```

$O(1)$ で動作します。

## Methods

### minimum

```cpp
int minimum() const;
```

最小値を返します。$O(1)$ で動作します。

### maximum

```cpp
int maximum() const;
```

最大値を返します。$O(1)$ で動作します。

### contains

```cpp
bool contains(int x) const;
```

$x$ が集合に含まれるかを返します。$O(\log \mathrm{bit})$ で動作します。

### successor

```cpp
int successor(int x) const;
```
集合に含まれる、$x$ より大きい最小の値を返します。そのような値がない場合は $-1$ を返します。$O(\log \mathrm{bit})$ で動作します。

### predecessor

```cpp
int predecessor(int x) const;
```
集合に含まれる、$x$ より小さい最大の値を返します。そのような値がない場合は $-1$ を返します。$O(\log \mathrm{bit})$ で動作します。

### insert

```cpp
void insert(int x);
```
集合に $x$ が含まれていない場合、挿入します。$O(\log \mathrm{bit})$ で動作します。

### erase

```cpp
void erase(int x);
```
集合に $x$ が含まれていない場合、削除します。$O(\log \mathrm{bit})$ で動作します。
