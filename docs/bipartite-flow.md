---
documentation_of: //graph/flow/bipartite-flow.hpp
---

## 概要

二部グラフに対するフロー. 

最大マッチングは Hopcroft-Karp に基づく実装. 最大流を求める Dinic と同じアルゴリズムだが, Hopcroft-Karp はこれを二部グラフ用に書き換えたもので定数倍が軽い. 残余グラフをBFSして各頂点までの最短距離を計算し, 最短距離のパスをDFSで見つけてフローを流す.

計算量が良いため基本的にはこれを使うと良い.

## 残余グラフについて
左側の頂点を $[0, n)$, 右側の頂点を $[n, n+m)$, 始点を $n+m$, 終点を $n+m+1$ としたグラフの残余グラフを用いると, いろいろできる.

このグラフを強連結成分分解する. すると各辺 $(u, v)$ (実際には $(u, v+n)$ なので注意すること) について, その辺が最大マッチングに必ず使うか, 必ず使わないか, それ以外かが分かり, 以下の手順で確認できる.

1. 頂点 $u, v$ が同じ強連結成分に含まれる → それ以外
2. 辺 $(u, v)$ が最大マッチングに含まれる → 必ず使う
3. それ以外(頂点 $u, v$ が異なる連結成分) → 必ず使わない

残余グラフについて始点から到達できる頂点をBFSなどにより全列挙する. 最小頂点被覆は, 左側かつ到達できない頂点 または 右側かつ到達できる点である. 最大安定集合はその補集合である. また残余グラフを見て頑張ると同じ計算量で辞書順最小頂点被覆も求まる.

## DAG の最小パス被覆

グラフ $G = (V, E)$ において, そのグラフの全ての頂点が $1$ つ以上のパスに含まれるようなパスの集合をを パス被覆 という.

特に, パス被覆の中でパスの数が最小のものを 最小パス被覆 という.

DAGの最小パス被覆は二部グラフの最大マッチング問題に帰着できる. 頂点を倍長して, 始点を左側に, 終点を右側に配置したグラフを考える. $V$ 本のパスがあれば被覆できることは自明. このグラフのマッチング一組に対して必要なパスを $1$ つ減らすことができるため, $V - $ (二部グラフの最大マッチング) が最小パス被覆となる.

## 使い方

* `BipartiteFlow(n, m)`:= 左側の頂点数 `n`, 右側の頂点数 `m` で初期化する.
* `add_edge(u, v)`:= 頂点 `u`, `v` 間に辺を張る.
* `max_matching()`:= 最大マッチングを返す.
* `erase_edge(a, b)`:= 頂点 `u`, `v` 間にある辺を削除する.
* `min_vertex_cover()`:= 最小頂点被覆を返す.
* `max_independent_set()`:= 最大安定集合を返す.
* `min_edge_cover()`:= 最小辺被覆を返す.
* `lex_max_matching()`:= 辞書順最小の最大マッチングを返す.
* `lex_min_vertex_cover(ord)`:= `ord` は左側の頂点を $[0, n)$, 右側の頂点を $[n, n + m)$ で表すとき, 優先度が高い順に頂点番号を並べた長さ $n + m$ の数列. このときの辞書順(優先度順)最小頂点被覆を返す.
* `build_residual_graph()`:= 左側の頂点を $[0, n)$, 右側の頂点を $[n, n+m)$, 始点を $n+m$, 終点を $n+m+1$ としたグラフを考えたとき, 残余グラフを返す.

## 計算量

* `add_edge(a, b)`: $O(1)$
* `erase_edge(a, b)`: $O(V)$
* `max_matching()`: $O(E \sqrt V)$
* `min_vertex_cover()`: $O(E \sqrt V)$
* `max_independent_cover()`: $O(E \sqrt V)$
* `min_edge_cover()`: $O(E \sqrt V)$
* `lex_max_matching()`: $O(E V)$ だと思うが早くできるのかも
* `lex_min_vertex_cover(ord)`: $O(E \sqrt V)$
* `build_residual_graph()`: $O(E + V)$
