---
title: Li Chao Tree
documentation_of: ../../data-structure/LiChaoTree.hpp
---

直線と線分を管理し、ある $x$ における $y$ の最小値/最大値を求めるデータ構造です。

## Declaration
```cpp
template <bool isMin>
class LiChaoTree;
```

`isMin` が `true` の場合最小値を、`false` の場合最大値を求めます。

## Constructor
```cpp
LiChaoTree(const std::vector<lint>& vec); // (1)
LiChaoTree(std::vector<lint>&& vec); // (2)
```

#### (1)
Li Chao Tree を構築します。$O(1)$ で動作します。

#### (2), (3)
`vec` に含まれる要素のクエリに答えられる Li Chao Tree を構築します。`vec` の長さを $N$ として $O(N)$ で動作します。

## Methods

### init
```cpp
void init(const std::vector<lint>& vec); // (1)
void init(std::vector<lint>&& vec); // (2)
```

`vec` に含まれる要素のクエリに答えられる Li Chao Tree に初期化します。

### add_line
```cpp
void addLine(lint a, lint b);
```

直線 $y=ax+b$ を追加します。

### add_segment
```cpp
void addSegment(int l, int r, lint a, lint b);
```

線分 $y=ax+b(l\leq x\leq r)$ を追加します。

### query
```cpp
std::pair<lint, int> query(int idx) const;
```

$x=\mathrm{vec\[idx\]}$ における答えと、それを与える直線/線分の index のペアを返します。

### clear
```cpp
void clear();
```

Li Chao Tree を初期化します。