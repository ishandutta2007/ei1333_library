---
title: Max Flow Lower Bound
documentation_of: //graph/flow/maxflow-lower-bound.hpp
---

各辺に容量の下限と上限があるフローネットワークを扱います。実行可能流の存在判定、および指定した始点から終点への最大流・最小流を求めることができます。

# コンストラクタ

```
MaxFlowLowerBound<flow_t, F>(int V)
```

頂点数 `V` のフローネットワークを作成します。`flow_t` は流量の型、`F` は最大流アルゴリズムのクラステンプレートです。

## 制約

- $0 \leq V$
- `F<flow_t>` は `add_edge`、`max_flow`、`INF`、`graph` を持つ

## 計算量

- $O(V)$

# add_edge

```
void add_edge(int from, int to, flow_t low, flow_t high)
```

頂点 `from` から `to` に、流量の下限が `low`、上限が `high` の有向辺を追加します。

## 制約

- $0 \leq \mathrm{from}, \mathrm{to} \lt V$
- $\mathrm{from} \neq \mathrm{to}$
- $0 \leq \mathrm{low} \leq \mathrm{high}$

## 計算量

- 償却 $O(1)$

# can_flow

```
bool can_flow()
```

すべての辺の下限制約と上限制約、および各頂点での流量保存則を満たす実行可能流が存在する場合 `true`、存在しない場合 `false` を返します。

```
bool can_flow(int s, int t)
```

頂点 `s` を始点、頂点 `t` を終点とする実行可能流が存在する場合 `true`、存在しない場合 `false` を返します。

## 制約

- $0 \leq s, t \lt V$
- $s \neq t$
- 辺の追加後、`can_flow`、`max_flow`、`min_flow` のいずれも呼び出していない

## 計算量

- `F` による最大流計算1回分。変換後のグラフは頂点数 $V+2$、辺数は元の辺数から $O(V)$ 増加する

# max_flow

```
optional<flow_t> max_flow(int s, int t)
```

すべての辺の下限制約と上限制約を満たす、頂点 `s` から `t` への最大流量を返します。実行可能流が存在しない場合は `nullopt` を返します。

## 制約

- $0 \leq s, t \lt V$
- $s \neq t$
- 辺の追加後、`can_flow`、`max_flow`、`min_flow` のいずれも呼び出していない

## 計算量

- `F` による最大流計算2回分。変換後のグラフは頂点数 $V+2$、辺数は元の辺数から $O(V)$ 増加する

# min_flow

```
optional<flow_t> min_flow(int s, int t)
```

すべての辺の下限制約と上限制約を満たす、頂点 `s` から `t` への最小流量を返します。流量は頂点 `s` からの流出量と頂点 `s` への流入量の差として定義されるため、負になることがあります。実行可能流が存在しない場合は `nullopt` を返します。

## 制約

- $0 \leq s, t \lt V$
- $s \neq t$
- 辺の追加後、`can_flow`、`max_flow`、`min_flow` のいずれも呼び出していない

## 計算量

- `F` による最大流計算2回分。変換後のグラフは頂点数 $V+2$、辺数は元の辺数から $O(V)$ 増加する

# output

```
void output(int M)
```

最初に追加した `M` 本の辺について、最後に求めた流量を追加順に1行ずつ出力します。

## 制約

- $0 \leq M \leq E$
- `can_flow`、`max_flow`、`min_flow` のいずれかを呼び出した後である

## 計算量

- $O(V + E)$
