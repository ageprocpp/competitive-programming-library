---
title: Binary Heap
documentation_of: ../../data-structure/BinaryHeap.hpp
---

Binary Heap(二項ヒープ) です。
値の集合を管理し、最小値を取得できます。

## Declaration
```cpp
template<class T, class Compare = std::less()>
class BinaryHeap;
```

`T` は扱うデータの型、`Compare` は比較関数オブジェクトです。

## Constructor
```cpp
BinaryHeap();
```

## Methods

### empty
```cpp
[[nodiscard]] bool empty() const noexcept;
```

ヒープが空かどうかを返します。$O(1)$ で動作します。

### size
```cpp
[[nodiscard]] size_t size() const noexcept;
```

ヒープの要素数を返します。$O(1)$ で動作します。

### top
```cpp
[[nodiscard]] T top() const;
```

ヒープ内の最小値を返します。$O(1)$ で動作します。

### pop
```cpp
void pop();
```

ヒープ内の最小値を削除します。$O(\log N)$ で動作します。

### push
```cpp
void push(const T& x);
```

ヒープに値 $x$ を追加します。$O(\log N)$ で動作します。

### emplace
```cpp
template<class... Args>
void emplace(Args&&... args);
```