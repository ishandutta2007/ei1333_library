---
documentation_of: //graph/others/bipartite-graph-edge-coloring.hpp
---

## 概要

二部グラフの辺彩色を求めるアルゴリズム. 辺彩色とは, 与えられたグラフの辺に色を付けることを指す. このとき隣接する(頂点を共有する)辺は全て異なる色になるようにする.

一般グラフの辺彩色数は, そのグラフの最大次数 $D$ または $D+1$ に一致する. 特に, 二部グラフに限定すると, その辺彩色数は 最大次数 $D$ に一致する.

まず, 与えられたグラフに対して最大次数 $D$ を維持したまま辺を追加したり縮約したりすることで$D-$正則グラフにする. $D$ が偶数の場合, オイラー閉路を求めて, 偶数番目に通った辺, 奇数番目に通った辺に分けて, 再帰的に解く. $D$ が奇数の場合, 完全マッチングを求めてそれらの辺を同じ色で塗った上で消して, 再帰的に解く. これらを繰り返すことで実際に $D$ 色の辺彩色を構成できる.

## 使い方

* `add_edge(a, b)`: $a$ から $b$ に辺を張る. $a$ は二部グラフの左側, $b$ は右側の頂点を指す.
* `build()`: 二部グラフの辺彩色を返す. 同じ色に塗るべき辺の番号が同じ配列に格納される. 辺の番号は `add_edge()` を呼び出した順に 0-indexed で付与される.

## 計算量

$O(M \sqrt N \log D)$

$N$: 頂点数, $M$: 辺の本数, $D$: 頂点の最大次数
