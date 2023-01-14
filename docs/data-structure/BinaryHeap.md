---
title: Binary Heap
documentation_of: ../../data-structure/BinaryHeap.hpp
---

Binary Heap(二項ヒープ) です。
値の集合を管理し、優先度付きキューを実現します。

## Declaration
```cpp
template <class T, class Compare = std::less()>
class BinaryHeap;
```

`T` は扱うデータの型、`Compare` は比較関数オブジェクトです。

## Constructor
```cpp
BinaryHeap();
```

$O(1)$ で動作します。

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

次に処理する要素を返します。$O(1)$ で動作します。

### pop
```cpp
void pop();
```

次に処理する要素を削除します。ヒープの含む要素数を $N$ として $O(\log N)$ で動作します。

### push
```cpp
void push(const T& x);
```

ヒープに値 $x$ を追加します。ヒープの含む要素数を $N$ として $O(\log N)$ で動作します。

### emplace
```cpp
template<class... Args>
void emplace(Args&&... args);
```

ヒープに値を構築して追加します。ヒープの含む要素数を $N$ として $O(\log N)$ で動作します。