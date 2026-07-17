---
title: Binomial Coefficient Prefix Sum Query
documentation_of: //math/combinatorics/binomial-prefix-sum-query.hpp
---

パスカルの三角形上を移動しながら、二項係数の Prefix Sum を求めます。問い合わせ位置が近い場合に有効です。

# コンストラクタ

```cpp
BinomialPrefixSumQuery<Mint>(int max_n)
```

クエリで与える $n$ の最大値を `max_n` で初期化します。初期位置は $(n,k)=(0,-1)$ で、保持する値は $0$ です。

## 制約

- $0 \leq$ `max_n` $\lt$ `Mint::mod()`
- `Mint` では $2$ の逆元を計算できる

## 計算量

`max_n` を $N$、`Mint::mod()` を $p$ とすると、

- 時間計算量: $O(N+\log p)$

# reset

```cpp
void reset()
```

位置を $(n,k)=(0,-1)$、保持する値を $0$ に戻します。二項係数の前計算は保持します。

## 計算量

- $O(1)$

# move

```cpp
Mint move(int n, int k)
```

位置を $(n,k)$ へ移動し、

$$
\sum_{i=0}^{k}\binom{n}{i}
$$

を返します。$k=-1$ の場合は $0$ を返します。

## 制約

- $0 \leq n \leq$ `max_n`
- $-1 \leq k \leq n$

## 計算量

移動前の位置を $(n_0,k_0)$ とすると、

$$
O\left(\lvert n-n_0\rvert+\lvert k-k_0-(n-n_0)\rvert\right)
$$

です。

# value

```cpp
Mint value() const
```

現在位置の二項係数の Prefix Sum を返します。

## 計算量

- $O(1)$
