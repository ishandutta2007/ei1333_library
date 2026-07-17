---
title: Bipartite Flow
documentation_of: //graph/flow/bipartite-flow.hpp
---

二部グラフの最大マッチングを Hopcroft-Karp 法で求めます。

左側の頂点を $[0, n)$、右側の頂点を $[0, m)$ とし、辺数を $E$ とします。頂点集合を一つの番号空間で返すメソッドでは、左側の頂点を $[0, n)$、右側の頂点を $[n, n + m)$ で表します。

# コンストラクタ

```cpp
BipartiteFlow(size_t n, size_t m)
```

左側の頂点数が `n`、右側の頂点数が `m` である、辺を持たない二部グラフを作成します。

## 制約

- $0 \leq n, m$

## 計算量

- $O(n + m)$

# add_edge

```cpp
void add_edge(int u, int v)
```

左側の頂点 `u` と右側の頂点 `v` の間に辺を追加します。

## 制約

- $0 \leq u \lt n$
- $0 \leq v \lt m$

## 計算量

- amortized $O(1)$

# erase_edge

```cpp
void erase_edge(int u, int v)
```

左側の頂点 `u` と右側の頂点 `v` の間にある辺を削除します。

## 制約

- $0 \leq u \lt n$
- $0 \leq v \lt m$
- 辺 $(u, v)$ が存在する

## 計算量

- $O(\deg(u) + \deg(v))$

# max_matching

```cpp
vector<pair<int, int>> max_matching()
```

最大マッチングに含まれる辺を返します。各要素 `(u, v)` は、左側の頂点 `u` と右側の頂点 `v` の組です。

## 計算量

- $O(E \sqrt{n + m})$

# lex_max_matching

```cpp
vector<pair<int, int>> lex_max_matching()
```

最大マッチングのうち、左頂点、右頂点の順で辞書順最小のものを返します。左頂点が未マッチである状態は、どの右頂点とマッチしている状態よりも大きいものとして扱います。

返り値の各要素 `(u, v)` は、左側の頂点 `u` と右側の頂点 `v` の組です。

## 計算量

- $O(n(E + n(n - K)))$

$K$ は最大マッチングの大きさです。

# min_vertex_cover

```cpp
vector<int> min_vertex_cover()
```

最小頂点被覆に含まれる頂点を返します。左側の頂点 `u` は `u`、右側の頂点 `v` は `n + v` として表します。

## 計算量

- $O(E \sqrt{n + m})$

# lex_min_vertex_cover

```cpp
vector<int> lex_min_vertex_cover(const vector<int>& ord)
```

最小頂点被覆のうち、`ord` で指定した優先度に関して辞書順最小のものを返します。`ord` は優先度が高い頂点から順に並べます。

左側の頂点 `u` は `u`、右側の頂点 `v` は `n + v` として表します。

## 制約

- `ord` は $[0, n + m)$ の順列

## 計算量

- $O(E \sqrt{n + m})$

# max_independent_set

```cpp
vector<int> max_independent_set()
```

最大独立集合に含まれる頂点を返します。左側の頂点 `u` は `u`、右側の頂点 `v` は `n + v` として表します。

## 計算量

- $O(E \sqrt{n + m})$

# min_edge_cover

```cpp
vector<pair<int, int>> min_edge_cover()
```

最小辺被覆に含まれる辺を返します。各要素 `(u, v)` は、左側の頂点 `u` と右側の頂点 `v` の組です。

辺被覆が存在しない場合は空の `vector` を返します。

## 計算量

- $O(E \sqrt{n + m})$

# build_risidual_graph

```cpp
vector<vector<int>> build_risidual_graph()
```

現在の最大マッチングに対応する残余グラフを返します。

残余グラフでは、左側の頂点を $[0, n)$、右側の頂点を $[n, n + m)$、始点を $n + m$、終点を $n + m + 1$ として表します。

## 強連結成分分解

この残余グラフを強連結成分分解すると、元のグラフの各辺 $(u, v)$ が最大マッチングに使われるかどうかを判定できます。右側の頂点 $v$ は、残余グラフ上では頂点 $n + v$ に対応します。

- $u$ と $n + v$ が同じ強連結成分に属する場合、辺 $(u, v)$ を使う最大マッチングと使わない最大マッチングの両方が存在する
- $u$ と $n + v$ が異なる強連結成分に属し、現在の最大マッチングが辺 $(u, v)$ を使っている場合、すべての最大マッチングが辺 $(u, v)$ を使う
- $u$ と $n + v$ が異なる強連結成分に属し、現在の最大マッチングが辺 $(u, v)$ を使っていない場合、どの最大マッチングも辺 $(u, v)$ を使わない

## 計算量

- $O(E \sqrt{n + m})$
